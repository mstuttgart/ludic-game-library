    /* Declaramos a imagem de fundo e o sprite sheet */
    ALLEGRO_BITMAP* sprite_sheet = al_load_bitmap( "lutador.png" );
    /* Criando o personagem */
    Sprite personagem;
    /* Recebe as dimensoes do sprite */
    int frame_w = al_get_bitmap_width (sprite_sheet)/NUM_COLUNAS;
    int frame_h = al_get_bitmap_height(sprite_sheet)/NUM_LINHAS;
    /* Ajustamos as posicoes do personagem */
    personagem.pos_x = 0;
    personagem.pos_y = 0;
    /* Variavel auxiliar para receber a posicao de cada frame dentro do sprite sheet */
    int frame_x, frame_y;

    /* Incializamos o vetor do animacoes com os bitmaps */
    for( int i = 0; i < MAX_FRAMES; i++ ){
          frame_x =         ( i % NUM_COLUNAS ) * frame_w;
          frame_y = ( int ) ( i / NUM_COLUNAS ) * frame_h;

          personagem.vetorSprites[ i ] = al_create_sub_bitmap( sprite_sheet, frame_x, frame_y, frame_w, frame_h );
    }
    /* Indica qual o frame atual do sprite */
    int frame_atual = 0;

    while( true )
    {
          /* Desenhamos o sprite na tela */
          al_draw_bitmap( personagem.vetorSprites[ frame_atual ], personagem.pos_x , personagem.pos_y, 0 );
          /* Atualiza a tela */
          al_flip_display();
          al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
          /* Incrementamos o frame e calculamos o novo valor. Assim, sempre teremos valores entre 0 e MAX_FRAMES-1*/
          frame_atual++;
          /* Se for o ultimo frame, voltamos ao primeiro */
          frame_atual = frame_atual % MAX_FRAMES;
          /* Aguarda alguns milesegundos */
          al_rest( 0.06 );
    }
