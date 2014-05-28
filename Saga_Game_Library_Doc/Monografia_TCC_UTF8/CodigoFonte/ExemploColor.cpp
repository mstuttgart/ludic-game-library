// Definição das cores vermelho e azul escuro usando o primeiro construtor.

    Color vermelho(255,0,0);   
    Color azulEscuro(0,0,139);

// Definição das cores rosa passando um nome pre-definido e das cores verde escuro e coral no formato html. 
// Note que o simbolo # e opcional.

    Color rosa("pink");
    Color verdeEsc("#006400");
    Color coral("FF7F50");

// Convertendo formatos.

	std::string cor;
	cor = vermelho.getName();   // cor = red
	cor = azulEsc.toHTML();     //  cor = #00008b 
