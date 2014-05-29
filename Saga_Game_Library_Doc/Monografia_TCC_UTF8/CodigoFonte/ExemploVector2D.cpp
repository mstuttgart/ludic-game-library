// Produto escalar entre a e b.

  Vector2D a(3,5);
  Vector2D b(3,9);
  
  float escalar = a.dotProduct(b); // escalar = 54

// Normalizacao de c.
  Vector2D c(4,3);
  c = c.normalize();   // c = ( 0.8, 0.6 )

// Soma entre vetores, com o operador + sobrecarregado.
  c = a + b; // saida = ( 6,14 )

