### B-árvores

As B-árvores são árvores utilizadas para funcionar bem com dispositivos de armazenamento secundários, tais como o HD (pois são mais lentos). Muitos sistemas de bancos de dados utilizam esse tipo de árvore.<p>
Em uma unidade de disco rígido típica, temos diversas lâminas que giram a uma velocidade constante em torno de um eixo, sendo essas lâminas cobertas por um material magnetizável. A unidade de disco pode ler ou escrever dados por meio de uma cabeça na extremidade de um braço controlador, onde quando esse braço está parado, pode-se dizer que a superfície que passa sob ela é denomidada trilha. Dessa forma, para armortizar o tempo de espera por conta dos movimentos mecânicos, um disco não acessa um dado de cada vez, mas sim várias páginas de bits de igual tamanho que aparecem consecutivamente dentro das trilhas, sendo uma página geralmente composta por 2^11 ou 2^14 bytes de comprimento.

Componentes principais do tempo de execução:
- Número de acessos ao disco
- Tempo de CPU

Para uma árvore B grande armazenada em disco, geralmente os fatores de ramificação (quantos nós possuem) estão na casa de 50 a 2000, dependendo da página em relação à chave utilizada.
