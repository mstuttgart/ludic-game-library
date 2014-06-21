
// Criamos uma instancia de video
Video video( 300, 100, DisplayMode::WINDOWED );

// Definimos o icone da janela do display
video.setIcon("sprite.jpg");

// Mudanca da cor de fundo da tela.
video.setBackgroundColor( Color("white") );

// Definindo um titulo para a janela.
video.setTitle( "Saga Game Library" );

// Atualizando o display.
video.refresh();