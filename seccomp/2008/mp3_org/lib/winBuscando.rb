module WinBuscando
  def self.show(dir)
    arq = File.join(File.dirname(__FILE__), "buscando.glade")
    @glade = GladeXML.new(arq) {|h| method(h)}
    @glade["imgMario"].set_file("img/mario.gif")
    
    @lista = MP3.arquivos(dir, @glade["lblDir"])
    @glade["winBuscando"].destroy
    return @lista
  end
  
end
