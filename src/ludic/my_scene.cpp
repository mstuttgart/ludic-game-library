#include "my_scene.hpp"
#include "color.hpp"

using namespace sgl;
using namespace sgl::event;
using namespace sgl::image;
using namespace sgl::font;
using namespace sgl::audio;

using namespace std;

//----------------------------------------------------

MyScene::MyScene( Video* _video ) : Scene(), video(_video) {}

//----------------------------------------------------

MyScene::~MyScene() {}

//----------------------------------------------------

void MyScene::initialize() {
	
	//Inicializamos o vetor de keys
	for( int i=0; i < ALLEGRO_KEY_MAX; i++ )
		keys[i] = false;

	spr.load( "Resource/mapas/personagem.tmx" );

	// Ajustamos posicao do sprite
	spr.setPosition( Vector2D( 100.0f, 100.0f ) );

	// Colocamos o sprite como visible
	spr.setVisible( true );

	//-------------------------------------------

	if( mapa.load( "Resource/rpg/mapa.tmx" ) )
		cout << "Carregou mapa com sucesso" << endl;

	mapa.setScreenDimension( video->getWidth(), video->getHeight() );
	
	video->setBackgroundColor( Color(145,184,60) );

	//-------------------------------------------

	layerManager.push_back( mapa.getLayer( "Piso" ) );
	layerManager.push_back( &spr );
	layerManager.push_back( mapa.getLayer( "Objetos" ) );
	layerManager.push_back( mapa.getLayer( "Arvores" ) );
	layerManager.push_back( mapa.getLayer( "Colisao" ) );

	l = mapa.getLayer( "Colisao" );

	//-----------------------------------------

	movex = 0;
	movey = 0;
	
	//-----------------------------------------

	musica.load( "Resource/audio/celtic.ogg", 4, 1024 );
	musica.setLoopingMode( sgl::audio::AudioPlayMode::PLAY_LOOP );
	musica.play();

}

//----------------------------------------------------

void MyScene::logic() {

	if( keys[ ALLEGRO_KEY_RIGHT] ) {
		spr.setCurrentAnimation( "Direita" );
	}

	if( keys[ ALLEGRO_KEY_LEFT] ) {
		spr.setCurrentAnimation( "Esquerda" );
	}

	if( keys[ ALLEGRO_KEY_UP] ) {
		spr.setCurrentAnimation( "Costas" );
	}

	if( keys[ ALLEGRO_KEY_DOWN] ) {
		spr.setCurrentAnimation( "Frente" );
	}

	if( keys[ ALLEGRO_KEY_ESCAPE] ) {
		this->setExitLoop( true );
	}
	
	if( keys[ ALLEGRO_KEY_V ] ) {
		l->setVisible( !l->isVisible() );
	}
	
	movex = movey = 0;
	
	movex += 5 * keys[ ALLEGRO_KEY_RIGHT ];
	movex -= 5 * keys[ ALLEGRO_KEY_LEFT  ];
	movey -= 5 * keys[ ALLEGRO_KEY_UP    ];
	movey += 5 * keys[ ALLEGRO_KEY_DOWN  ];

	// Verificamos se podemos nos movimentar no eixo X
	if( l->checkCollision( spr, movex, 0, 2 ) ) {
		movex = 0;
	}

	if( l->checkCollision( spr, 0, movey, 2 ) ) {
		movey = 0;
	}

	if( movex || movey ) {
		desloc.setCoordinates( movex, movey );
		spr.move( desloc );
		spr.nextFrame();
	}

}

//----------------------------------------------------

void MyScene::render() {

	for( unsigned int i = 0; i < layerManager.size(); i++ ) {
		layerManager.at( i )->draw();
	}
}

//---------------------------------------------------

void MyScene::finalize() {
}

//----------------------------------------------------

void MyScene::displayClose() {
	this->setExitLoop( true );
}

//----------------------------------------------------

void MyScene::keyDown( const KeyEvent& keyEvent ) {
	keys[keyEvent.getKeyCode()] = true;
}

//----------------------------------------------------

void MyScene::keyRelease( const KeyEvent& keyEvent ) {
	keys[keyEvent.getKeyCode()] = false;
}

//----------------------------------------------------
