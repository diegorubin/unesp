program arvorebin;

uses unit_arvorebin;
var
	secoia:arvore;
	instrucoes:text;
	arq_arvore,arq_grafico:text;
	valor,i,a_nivel:integer;
	instrucao:char;

procedure imprime_em_dot(p:arvore);
begin
	if(p <> nil) then
	begin
		if( p^.esq <> nil) then writeln(arq_grafico,'	',p^.inf,'->',p^.esq^.inf);
		if( p^.dir <> nil) then writeln(arq_grafico, '	',p^.inf,'->',p^.dir^.inf);
		imprime_em_dot(p^.esq);
		imprime_em_dot(p^.dir);
	end;	
end;

procedure salva(p:arvore);
begin
	if(p <> nil) then
	begin
		writeln(arq_arvore,p^.inf);
		salva(p^.esq);
		salva(p^.dir);
	end;	
end;

function existeArquivo(nomeArq: string): boolean;
var
	arquivo: text;
begin
	{$I-}

	assign(arquivo, nomeArq);
	reset(arquivo);
	close(arquivo);

	{$I+}
	existeArquivo:= (IOResult = 0) and (nomeArq <> '');
end;

begin
	a_nivel:=0;
	assign(arq_grafico, 'arvore.dot');
	assign(instrucoes, 'instrucoes.txt');
	assign(arq_arvore, 'arvore.tre');
	
	rewrite(arq_grafico);
	reset(instrucoes);

	readln(instrucoes,valor);
	readln(instrucoes,instrucao);

	if( existeArquivo('arvore.tre')) then reset(arq_arvore)
	else 
		begin
			instrucao:='n';
			rewrite(arq_arvore);
			writeln(arq_arvore,valor);
			writeln(arq_arvore,27001);
			close(arq_arvore);
			reset(arq_arvore);
		end;
	readln(arq_arvore,i);
	monta_arvore(secoia,i);
	readln(arq_arvore,i);
	while ( i <> 27001) do
	begin
		insere(secoia,i);
		readln(arq_arvore,i);
	end;
	case instrucao of
		'i':insere(secoia,valor);
		'r':remove(secoia,valor);
		'b':nivel_arvore(secoia,a_nivel,-1);
	end;
	writeln('nivel:',a_nivel);
	writeln(arq_grafico,'digraph G {');
	imprime_em_dot(secoia);

	writeln(arq_grafico,'}');
	rewrite(arq_arvore);
	salva(secoia);
	writeln(arq_arvore,27001);

	close(arq_grafico);
	close(instrucoes);
	close(arq_arvore);
	
end.
