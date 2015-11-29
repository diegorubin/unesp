require "mp3_utils"

module WinEdicao
  def self.show(artista, album, titulo, caminho)
    @caminho = caminho
    arq = File.join(File.dirname(__FILE__), "edicao.glade")
    @glade = GladeXML.new(arq) {|h| method(h)}
    
    @glade["entArtista"].set_text(artista)
    @glade["entAlbum"].set_text(album)
    @glade["entTitulo"].set_text(titulo)
    @glade["lblCaminho"].set_markup("<i>Arquivo:#{@caminho}</i>  ")
    
    @glade["winEdicao"].show
  end
  def self.salvar
    artista = @glade["entArtista"].text
    album = @glade["entAlbum"].text
    titulo = @glade["entTitulo"].text
    MP3.salvar(@caminho, artista, album, titulo)
    @glade["winEdicao"].destroy
    WinPrincipal.atualizar(@caminho)
   
  end
  
end