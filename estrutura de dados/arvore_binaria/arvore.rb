#!/usr/bin/env ruby

require "libglade2"

Gtk.init

def sair
	`rm arvore.tre arvore.png arvore.dot`
	Gtk.main_quit()
end

def executar
	if($glade["rdbInserir"].active?) 
		acao = 'i'
	end
	if($glade["rdbRemover"].active?)
		acao = 'r'
	end
	if(!$glade["rdbLimpar"].active?)
		valor = $glade["entValor"].text
		`echo #{valor} > instrucoes.txt`
		`echo "#{acao}" >> instrucoes.txt`
		`./arvorebin`
		`dot -Tpng arvore.dot -o arvore.png`
		$glade["imgArvore"].set_file("arvore.png")
	else
		$glade["imgArvore"].set_file("vazia.png")
		`rm arvore.tre arvore.png arvore.dot`
	end
end

$arquivo_glade = File.join(File.dirname(__FILE__), "arvore.glade")
$glade = GladeXML.new($arquivo_glade) { |h| method(h) }

Gtk.main
