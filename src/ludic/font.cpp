#include "font.hpp"

using namespace sgl::font;
using namespace sgl;
using namespace std;

//////////////////////////////////////////////////////////////

Font::Font() : fontResource( nullptr ), alignment( FontAlignment::LEFT ), 
color( Color( 0, 0, 0 ) ){}

//////////////////////////////////////////////////////////////

Font::Font( const String& fileName, unsigned int fontSize ) :
	fontResource( nullptr ), alignment( FontAlignment::LEFT ), color( Color( 0, 0, 0 ) ) {

	// Lancamos uma excecao caso o carregamento nao tenha dado certo
	if( !load( fileName, fontSize ) )
		throw sgl::Exception( "Error to load Font" );

}

//////////////////////////////////////////////////////////////

Font::~Font() {}

//////////////////////////////////////////////////////////////

bool Font::load( const String& fileName, unsigned int fontSize ) {
	
	try{
		// Carregamos a fonte
		fontResource = FontResource::createFontResource( fileName, fontSize );
	}
	catch( sgl::Exception& ex )
	{
		cout << ex.what() << endl;
		return false;
	}
	
	return true;
}

//////////////////////////////////////////////////////////////

void Font::drawText() {

	//Desenhamos o texto no display
	al_draw_text( *fontResource, color, position.getX(), position.getY(),
	              ( int ) alignment, text.c_str() );

}

//////////////////////////////////////////////////////////////

void Font::setColorFont( const Color& color ) {
	this->color = color;
}

//////////////////////////////////////////////////////////////

void Font::setPosition ( const Vector2D& position ) {
	this->position = position;
}

//////////////////////////////////////////////////////////////

void Font::setText ( const String& usrText ) {
	this->text = usrText;
}

//////////////////////////////////////////////////////////////

void Font::setAlignment( FontAlignment align ) {
	this->alignment = align;
}

//////////////////////////////////////////////////////////////

int Font::getLineHeight() const {
	return al_get_font_line_height( *fontResource );
}

//////////////////////////////////////////////////////////////

int Font::getTextWidth() const {
	return al_get_text_width( *fontResource, text.c_str() );
}

//////////////////////////////////////////////////////////////

int Font::getTextWidth( const String& strText ) const {
	return al_get_text_width( *fontResource, strText.c_str() );
}

//////////////////////////////////////////////////////////////

BoundingBox Font::getTextDimension( const String& str ) {
	
	int x, y, w, h;
	
	// Capturamos as dimensoes do texto
	al_get_text_dimensions( *fontResource, str.c_str(), &x, &y, &w, &h );

	return BoundingBox( Vector2D( x, y ), w, h );

}

//////////////////////////////////////////////////////////////

BoundingBox Font::getTextDimension() {

	int x, y, w, h;

	// Capturamos as dimensoes do texto
	al_get_text_dimensions( *fontResource, text.c_str(), &x, &y, &w, &h );

	return BoundingBox( Vector2D( x, y ), w, h );
}

//////////////////////////////////////////////////////////////

const FontAlignment& Font::getAlignment() const {
	return alignment;
}

//////////////////////////////////////////////////////////////

const Color& Font::getColor() const {
	return color;
}

//////////////////////////////////////////////////////////////

const FontResource* Font::getFontResource() {
	return fontResource;
}

//////////////////////////////////////////////////////////////

const Vector2D& Font::getPosition() const {
	return position;
}

//////////////////////////////////////////////////////////////

const String& Font::getText() const {
	return text;
}

//////////////////////////////////////////////////////////////
