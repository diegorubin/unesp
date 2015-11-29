require "mp3info"

module MP3
  def self.arquivos(dir,label)
    @lista = []
    procurar(dir,label)
  end
  
  private
  def self.procurar(dir,label)
    Dir.entries(dir).each do |entrada|
      label.set_markup("<i>#{dir}/#{entrada}</i>")
      Gtk.main_iteration
      if (File.directory?(dir + "/" + entrada) and (entrada != "." and entrada != ".."))
        procurar(dir + "/" + entrada,label)
      else
        if(File.extname(entrada) == ".mp3")
          mp3 = []
          mp3[0] = dir + "/#{entrada}"
          Mp3Info.open(mp3[0]) do |arq_mp3|
            mp3[1] = arq_mp3.tag.artist
            mp3[2] = arq_mp3.tag.album
            mp3[3] = arq_mp3.tag.title
          end
          @lista << mp3
        end
      end
    end
    return @lista
  end
  
  def self.salvar(dir, artista, album, titulo)
    Mp3Info.open(dir) do |arq_mp3|
      arq_mp3.tag.artist = artista
      arq_mp3.tag.album = album
      arq_mp3.tag.title = titulo
    end
  end
  def self.inf(dir)
    inf = []
    Mp3Info.open(dir) do |arq_mp3|
      inf[0] = arq_mp3.tag.artist
      inf[1] = arq_mp3.tag.album
      inf[2] = arq_mp3.tag.title
    end
    inf
  end
end
