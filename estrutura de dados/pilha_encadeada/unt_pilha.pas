{Trabalho de Estrutura de Dados 1
 Escrito por Diego Rubin
 Compilador usado para teste: FreePascal 2.0.4
 Plataforma: Linux 2.6 Fedora 7(Moonshine)}
unit unt_pilha;

interface

type TipoElem = integer;
type ppilha = ^pconteudo;
	pconteudo = record
		item:TipoElem;
		prox:ppilha;
	end;
	pilha = record
		base:ppilha;
		topo:ppilha;
	end;	

function putErro(erro:integer):string;
procedure inicializar_pilha(var p:pilha);
procedure push(x:integer; var p:pilha);
function topo(p:pilha):TipoElem;
function pilVaz(p:pilha):boolean;
procedure esvPil(var p:pilha);
procedure pop(var p:pilha);

implementation
{funcao que retorna a descricao do erro que foi requerido}
function putErro(erro:integer):string;
begin
	case erro of
		1:putErro:='A Pilha esta VAZIA';
	end;
end;
{Para facilitar o uso desta unit, foi criado este procedimento.
Este procedimento simplesmeste inicializa os ponteiros iniciais da pilha}
procedure inicializar_pilha(var p:pilha);
begin
	new(p.base);
	p.topo:= p.base;
end;

procedure push(x:integer; var p:pilha);
begin
	new(p.topo^.prox);
	p.topo := p.topo^.prox;
	p.topo^.item := x;
	p.topo^.prox:= nil;
end;

function topo(p:pilha):TipoElem;
begin
	if(pilVaz(p)) then
		begin 
			write(putErro(1));
			topo:= 0;
		end
	else
		topo:= p.topo^.item;
	
end;

function pilVaz(p:pilha):boolean;
begin
	pilVaz:=(p.topo = p.base);
end;

procedure esvPil(var p:pilha);
begin
	while(p.topo<>p.base) do
		pop(p);
	
end;

procedure pop(var p:pilha);
var
	controle:ppilha;
begin
	if(pilVaz(p)) then
		write(putErro(1))
	else
		begin
			controle:= p.base;
			while (controle^.prox <> p.topo) do
				controle:= controle^.prox;
			p.topo:=controle;
			dispose(controle^.prox);
		end;
	
end;

end.{ end da unit }
