unit unit_arvorebin;

interface
type tipo = integer;
type arvore = ^a_no;
	 a_no = record
		inf:tipo;
		esq:arvore;
		dir:arvore
	end;

procedure monta_arvore(var p:arvore; inicial:tipo);
procedure insere(var p:arvore; x:tipo);
function busca(p:arvore; x:tipo):arvore;
function busca_pai(p:arvore; x:arvore):arvore;
function busca_antecessor(x:arvore):arvore;
procedure remove(var p:arvore; x:tipo);
procedure nivel_arvore(p:arvore;var nivel:integer;externo:integer);

implementation

{procedimento que cria um novo nó da árvore}
procedure monta_arvore(var p:arvore; inicial:tipo);
begin
	new(p);
	p^.inf:= inicial;
	p^.esq:= nil;
	p^.dir:= nil; 
end;
{procedimento que cria um novo nó e o coloca na árvore.
E o faz ordenando. Árvore de busca binária.}
procedure insere(var p:arvore; x:tipo);
begin
	if(p <> nil) then
	begin
		if( x < p^.inf) then insere(p^.esq,x)
		else if(x > p^.inf) then insere(p^.dir,x);
	end
	else
		monta_arvore(p,x);

end;
{Procedimento recursivo que encontra o endereço de um elemento procurado.
Para facilitar o uso no programa principal, foi implementado a função busca. O 
mesmo ocorre com as funções e procedimentos e buscam o antecessor e o pai.}
procedure pbusca(p:arvore;x:tipo; var buscado:arvore; var encontrado:boolean);
begin
	if((p <> nil) and (not encontrado)) then
	begin
		if (p^.inf = x) then  
		begin
			buscado:= p;
			encontrado:=TRUE;
		end
		else if( x < p^.inf) then pbusca(p^.esq,x,buscado,encontrado)
		else pbusca(p^.dir,x,buscado,encontrado);
	end;
end;

function busca(p:arvore; x:tipo):arvore;
var
	encontrado:boolean;
	aux:arvore;
begin
	aux:=nil;
	encontrado:=FALSE;
	pbusca(p,x,aux,encontrado);
	busca:=aux;
end;

procedure pbusca_pai(p:arvore;x:arvore; var buscado:arvore; var encontrado:boolean);
begin
	if((p <> nil) and (not encontrado)) then
	begin
		if ((p^.dir = x) or (p^.esq = x)) then
		begin
			buscado:= p;
			encontrado:=TRUE;
		end
		else if( x^.inf < p^.inf) then pbusca_pai(p^.esq,x,buscado,encontrado)
		else pbusca_pai(p^.dir,x,buscado,encontrado);
	end;
end;

function busca_pai(p:arvore; x:arvore):arvore;
var
	encontrado:boolean;
	aux:arvore;
begin
	aux:=nil;
	encontrado:=FALSE;
	pbusca_pai(p,x,aux,encontrado);
	busca_pai:=aux;
end;

procedure pbusca_antecessor(x:arvore;var buscado:arvore;var encontrado:boolean);
var 
	p:arvore;
begin
	if(x^.esq <> nil) then 
	begin
		p:= x^.esq;
		if(p^.dir = nil) then 
			buscado:=p
		else
			while (p <> nil) do
			begin
				buscado:= p;
				p:=p^.dir;
			end;
	end;
end;

function busca_antecessor(x:arvore):arvore;
var
	aux:arvore;
	encontrado:boolean;
begin
	aux:=nil;
	encontrado:=FALSE;
	pbusca_antecessor(x,aux,encontrado);
	busca_antecessor:=aux;
end;
{Função que encontra a situação em que encontra-se o nó que será removido.}
function situacao(p:arvore):integer;
begin
	if(p^.esq <> nil) then situacao:=2
	else if(p^.dir <> nil) then situacao:=3
	else situacao:=4;
	if((p^.esq <> nil) and (p^.dir <> nil)) then situacao:=1;
end;
{Procedimento que remove um nó da árvore.
Como expecificado, se o nó a ser removido tiver dois filhos, fica em seu lugar o antecessor
in-ordem, se houver apenas um filho, este fica em seu lugar e se não houver filhos o nó é apenas removido.}
procedure remove(var p:arvore;x:tipo);
var
	arv,pai,pai_ant,ant:arvore;
	sit:integer;
begin
	arv:= busca(p,x);
	pai:= busca_pai(p,arv);
	ant:=busca_antecessor(arv);
	sit:= situacao(arv);
	case sit of
	1:begin
		if(arv^.esq^.dir <> nil) then 
		begin
			pai_ant:=busca_pai(p,ant);
			ant^.esq:= arv^.esq;
			pai_ant^.dir:=nil;
		end;
		ant^.dir:= arv^.dir;
		if(pai <> nil) then
			if( pai^.esq = arv) then
				pai^.esq:=ant
			else
				pai^.dir:=ant
		else
			p:= ant;
	end;
	2:if(pai <> nil) then
			if(pai^.esq = arv) then pai^.esq:=arv^.esq
			else pai^.dir:= arv^.esq
		else
			p:=arv^.esq;
	3:if(pai <> nil) then 
			if(pai^.esq = arv) then pai^.esq:=arv^.dir
			else pai^.dir:= arv^.dir
		else
			p:=arv^.dir;
	4:if(pai^.esq = arv) then pai^.esq:=nil
		else pai^.dir:= nil;
	end;{end case}
	dispose(arv);
	
end;

procedure nivel_arvore(p:arvore;var nivel:integer;externo:integer);
begin
	if(p <> nil) then
	begin
		externo:=externo +1;
		nivel_arvore(p^.esq,nivel,externo);
		nivel_arvore(p^.dir,nivel,externo);
	end;
	if(nivel < externo) then
		nivel:=externo;
end;

end.{end da unit}
