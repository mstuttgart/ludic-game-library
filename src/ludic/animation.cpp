#include "animation.hpp"

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////////

Animation::Animation( const vector< TMXTileSet * > &tmxTileset,
                      const vector< TMXLayer::DataInfo > &data,
                      ImageResource *baseImages[], const String &_label )
    : currentFrame( 0 ), repeat( true ), label(_label)
{

    // Variaveis temporarias
    int x, y, w, h;
    unsigned int firstGid;
    ImageResource *bitmap;

    for ( unsigned int i = 0; i < data.size(); i++ )
    {

        for ( unsigned int j = 0; j < tmxTileset.size(); j++ )
        {

            // Pegamos o primeiro id do tileset
            firstGid = tmxTileset[j]->getFirstGid();

            if ( data[i].gid >= firstGid && data[i].gid <= tmxTileset[j]->getLastGid() )
            {

                // Recebemos as dimensoes do tile do tileset
                w = tmxTileset[j]->getTileWidth();
                h = tmxTileset[j]->getTileHeight();

                // Encontramos a posicao do frame dentro
                // do seu respectivo tileset
                x = ( ( data[i].gid - firstGid ) % tmxTileset[j]->getColums() ) * w;
                y = ( ( data[i].gid - firstGid ) / tmxTileset[j]->getColums() ) * h;

                // Criamos um subbitmap com estas coordenadas
                // Este subbitmap representa o frame em questao
                bitmap = baseImages[j]->getSubImageResource( x, y, w, h );

                // Inserimos o bitmap no vetor
                frames.push_back( new Frame( data[i].gid, w, h, bitmap ) );

            }//if

        }//for

    }//for i

}

//////////////////////////////////////////////////////////////////

Animation::~Animation()
{

    // Percorremos o vetor com os sub bitmaps, deletando-os
    for ( unsigned int i = 0; i < frames.size(); i++ )
    {

        if ( frames[i] != nullptr )
            delete frames[i];

    }//for

    frames.clear();

}

//////////////////////////////////////////////////////////////////

void Animation::nextFrame()
{

    currentFrame++;

    // Verificamos se devemos incrementar o frame de acordo
    // com o tipo de animacao. Se for em loop nos voltamos ao indice zero,
    // caso contrário nós deixamos a animacao presa em seu ultimo frame.
    if ( currentFrame == frames.size() )
    {
        currentFrame = repeat ? 0 : frames.size() - 1;
    }

    /*currentFrame = currentFrame % frames.size()

    currentFrame = !repeat ? frames.size() : currentFrame;

    if ( repeat && currentFrame == frames.size() ) {
        currentFrame = 0;
    }//if*/

}

//////////////////////////////////////////////////////////////////

int Animation::getCurrentFrameIndex() const
{
    return currentFrame;
}

//////////////////////////////////////////////////////////////////

const Frame *Animation::getCurrentFrame() const
{
    return frames.at( currentFrame );
}

//////////////////////////////////////////////////////////////////

int Animation::getFrameWidth() const
{
    return frames.at( currentFrame )->getWidth();
}

//////////////////////////////////////////////////////////////////

int Animation::getFrameHeight() const
{
    return frames.at( currentFrame )->getHeight();
}

//////////////////////////////////////////////////////////////////

void Animation::reset()
{
    currentFrame = 0;
}

//////////////////////////////////////////////////////////////////

void Animation::setRepeat( bool repeat )
{
    this->repeat = repeat;
}

//////////////////////////////////////////////////////////////////

bool Animation::isRepeat()
{
    return repeat;
}

//////////////////////////////////////////////////////////////////

void Animation::previusFrame()
{

    currentFrame--;

    // Verificamos se devemos decrementar o frame de acordo
    // com o tipo de animacao. Se for em loop nos voltamos ao ultimo frame da animacao,
    // caso contrário nós deixamos a animacao presa em seu primeiro frame.
    if ( currentFrame == 0 )
    {
        currentFrame = repeat ? frames.size() - 1 : 0;
    }

    /*if ( currentFrame != 0 )
        currentFrame--;*/

}

//////////////////////////////////////////////////////////////////

int Animation::length() const
{
    return frames.size();
}

//////////////////////////////////////////////////////////////////

const String &Animation::getLabel() const
{
    return label;
}

//////////////////////////////////////////////////////////////////