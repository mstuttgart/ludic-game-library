
ImageResource* ImageResource::loadImageResource( const String& fileName ) {

	// Inciamos a string com a msg de carregamento
	String str( "File " + fileName );
	// Pegamos uma instancia do mapa
	ResourceManager* rscMap = ResourceManager::Instance();
	// Verificamos se o recurso ja foi carregado
	ImageResource* rsc = static_cast<ImageResource*> ( rscMap->getResource( fileName ) ) ;

	// Se for NULL devemos alocar um novo ImageResource e inserir no mapa
	if( !rsc ) {
	  
		// Carregamos o bitmap
		ALLEGRO_BITMAP* bitmap = al_load_bitmap( fileName.c_str() );

		if( !bitmap ) {
			throw sgl::Exception( "ERROR: Error to load ImageResource: " + fileName );
			return nullptr;
		}

		// Criamos um novo recurso
		rsc = new ImageResource( fileName, bitmap );
		// Adicionamos o resource ao mapa
		rscMap->addResource( fileName, rsc );
		str += " loaded successfully!";
	}
	else {
		str += " already exists!";
	}

	// Imprimimos o resultado da criacao da imagem
	std::cout << str << std::endl;
	return rsc;
}
 
