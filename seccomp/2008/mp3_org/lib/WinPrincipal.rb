require "WinEdicao"
require "winBuscando"

module WinPrincipal
  def self.show
    arq = File.join(File.dirname(__FILE__), "mp3_org.glade")
    @glade = GladeXML.new(arq) {|h| method(h)}
    
    
  end
  
  def self.atualizar(caminho)
    for i in 0..@lista.length-1
      if(@lista[i][0] == caminho)
        inf = MP3.inf(caminho)
        @lista[i][1] = inf[0]
        @lista[i][2] = inf[1]
        @lista[i][3] = inf[2]
      end
    end
    if(@glade["trvArquivos"].model != nil)
      @glade["trvArquivos"].remove_column(@col_artista)
      @glade["trvArquivos"].remove_column(@col_album)
      @glade["trvArquivos"].remove_column(@col_arquivo)
      @glade["trvArquivos"].remove_column(@col_titulo)
    end
    
    lstArquivos = Gtk::ListStore.new(String, String, String, String)
    
    @lista.each do |arquivo|
      iter = lstArquivos.append
      iter[0] = arquivo[1]
      iter[1] = arquivo[2]
      iter[2] = arquivo[3]
      iter[3] = arquivo[0]
    end
    
    @glade["trvArquivos"].set_model(lstArquivos)
    
    renderer = Gtk::CellRendererText.new
    
    @col_artista = Gtk::TreeViewColumn.new("Artista", renderer)
    @col_artista.set_cell_data_func(renderer) do |@col_artista, renderer, model, iter|
      renderer.text = iter[0]
    end
    
    @col_album = Gtk::TreeViewColumn.new("Album", renderer)
    @col_album.set_cell_data_func(renderer) do |@col_album, renderer, model, iter|
      renderer.text = iter[1]
    end
    
    @col_titulo = Gtk::TreeViewColumn.new("Titulo", renderer)
    @col_titulo.set_cell_data_func(renderer) do |@col_titulo, renderer, model, iter|
      renderer.text = iter[2]
    end
    
    @col_arquivo = Gtk::TreeViewColumn.new("Arquivo", renderer)
    @col_arquivo.set_cell_data_func(renderer) do |@col_arquivo, renderer, model, iter|
      renderer.text = iter[3]
    end
    
    @glade["trvArquivos"].append_column(@col_artista)
    @glade["trvArquivos"].append_column(@col_album)
    @glade["trvArquivos"].append_column(@col_titulo)
    @glade["trvArquivos"].append_column(@col_arquivo)
    
    
  end
  private
  def self.procurar
    if(@glade["trvArquivos"].model != nil)
      @glade["trvArquivos"].remove_column(@col_artista)
      @glade["trvArquivos"].remove_column(@col_album)
      @glade["trvArquivos"].remove_column(@col_arquivo)
      @glade["trvArquivos"].remove_column(@col_titulo)
    end
    
    dir_mp3 = @glade["fcbDir"].current_folder
    @lista = WinBuscando.show(dir_mp3)
    
    lstArquivos = Gtk::ListStore.new(String, String, String, String)
    
    @lista.each do |arquivo|
      iter = lstArquivos.append
      iter[0] = arquivo[1]
      iter[1] = arquivo[2]
      iter[2] = arquivo[3]
      iter[3] = arquivo[0]
    end
    
    @glade["trvArquivos"].set_model(lstArquivos)
    
    renderer = Gtk::CellRendererText.new
    
    @col_artista = Gtk::TreeViewColumn.new("Artista", renderer)
    @col_artista.set_cell_data_func(renderer) do |@col_artista, renderer, model, iter|
      renderer.text = iter[0]
    end
    
    @col_album = Gtk::TreeViewColumn.new("Album", renderer)
    @col_album.set_cell_data_func(renderer) do |@col_album, renderer, model, iter|
      renderer.text = iter[1]
    end
    
    @col_titulo = Gtk::TreeViewColumn.new("Titulo", renderer)
    @col_titulo.set_cell_data_func(renderer) do |@col_titulo, renderer, model, iter|
      renderer.text = iter[2]
    end
    
    @col_arquivo = Gtk::TreeViewColumn.new("Arquivo", renderer)
    @col_arquivo.set_cell_data_func(renderer) do |@col_arquivo, renderer, model, iter|
      renderer.text = iter[3]
    end
    
    @glade["trvArquivos"].append_column(@col_artista)
    @glade["trvArquivos"].append_column(@col_album)
    @glade["trvArquivos"].append_column(@col_titulo)
    @glade["trvArquivos"].append_column(@col_arquivo)
    
  end
  def self.editar
    row = @glade["trvArquivos"].selection.selected
    WinEdicao.show(row[0],row[1], row[2], row[3])
  end
  def self.sair
    Gtk.main_quit
  end
end
