// Definicao das cores vermelho e azul escuro usando o primeiro construtor.

    Color vermelho(255,0,0);   
    Color azulEscuro(0,0,139);

// Definicao das cores rosa passando um nome pre-definido 
// e das cores verde escuro e coral no formato hexadecimal 
// utilizado em html. 
// Note que o simbolo # e opcional.

    Color rosa("pink");
    Color verdeEsc("#006400");
    Color coral("FF7F50");

// Convertendo formatos.

	std::string cor;
	cor = vermelho.getName();   // cor = red
	cor = azulEsc.toHTML();     //  cor = #00008b 
