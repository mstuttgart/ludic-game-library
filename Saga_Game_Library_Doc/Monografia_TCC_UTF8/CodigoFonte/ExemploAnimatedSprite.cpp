// Declaramos o sprite
AnimatedSprite spr;
// Carregamos o arquivo tmx
spr.load( "personagem.tmx" );
// Ajustamos posicao do sprite
spr.setPosition( Vector2D( 100.0f, 100.0f ) );
// Colocamos o sprite como visible
spr.setVisible( true );

while( true )
{
    // Desenhamos o sprite
    spr.draw();
    // Avancamos para o proximo frame
    spr.nextFrame();
    // Atualizamos o display
    video.reflesh();
    // Aguarda alguns milesegundos
    al_rest( 0.06 );
}