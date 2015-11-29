program teste_pilha;

uses unt_pilha,crt;

var
	memoria:pilha;

begin
	inicializar_pilha(memoria);
	if(pilVaz(memoria)) then writeln(putErro(1));
	push(5,memoria);
	if(pilVaz(memoria)) then writeln(putErro(1));
	writeln(topo(memoria));
	push(155,memoria);
	writeln(topo(memoria));
	pop(memoria);
	writeln(topo(memoria));
	push(45,memoria);
	writeln(topo(memoria));
	pop(memoria);
	writeln(topo(memoria));
	esvPil(memoria);
	if(pilVaz(memoria)) then writeln(putErro(1));
	
end.