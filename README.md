# Exercicio02

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/Language-C-blue"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20in-VSCode-red"/> 
</div>
<br>
Crie uma lista linear que consiga armazenar um conjunto de 100 nomes quaisquer, os quais serão salvos de forma aleatória. Feito a estrutura crie as seguintes ações:
<ul>
  <li>Uma função que consiga identificar replicações na lista, ou seja, nomes iguais. Remova todas as réplicas sem mover os ”ponteiro“.</li>
  <li>Como você gerenciaria os espaços em branco para novas inserções? Qual seria o custo dessas novas inserções?</li>
</ul>

# Solução

<p align="justify">
Os espaçoes em brancos são tratados como espaços aonde novos nomes podem ser inseridos. O novo custo para inserções será o custo para verificar se há espaços em brancos se houver colocar por cim deles senão colocar na última posição mais o custo de inserir mais o custo para ver se le é repitido e se ele for repitido tornar ele um espaço em branco.
</p>

<p align="justify">A estrutura da lista linear para este progama é, cada item desta lista tem um <strong>value</strong> do tipo char[] que é um nome e <strong>rep</strong> do tipo int que é o número de vezes que o nome repitiu:</p>
<p align="center">
<img src="imgs/estrutura.png"> 
</p>

<p align="justify">Os métodos a seguir servem para deixar a lista vazia e para imprimmir a lista, na hora de imprimir não são mostrados os espaços em brancos que aparecem depois de remover as repetições:</p>
<p align="center">
<img align="center" src="imgs/parte1.png">
</p>

<p align="justify">Para inserir algum item na lista é utilizado o método a seguir, mas na hora de inserir é necessário procurar na lista se há algum espaço em branco na lista se haver o item é adicionado por cima senão haver espaço em branco o item é adicionado na ultima posição possível o método a lado mostra como é achado um espaço em branco:</p>
<p align="center">
<img align="center" src="imgs/insere.png">
<img align="center" src="imgs/acaharsb.png">
</p>

<p align="justify">Após a inserção de um item na lista precisa-se verificar se há algum nome repetido na lista que feito pelo método a seguir, quando um nome repetido é achado o valeu dele é mudado para vazio e rep para -1 para simbolizar que ele virou um espaço em branco:</p>
<p align="center">
<img align="center" src="imgs/norepeat.png">
</p>

<p align="justify">Para remover algum item o progama utiliza o método a seguir:</p>
<p align="center">
<img align="center" src="imgs/remove.png">
</p>

<p align="justify">Para preencher a lista linear com os nomes há um método que lé os nomes de um arquivo passado pelo usuário, após todos os nomes serem inseridos a lista o método NoRepeat é chamado para tirar os nomes repitidos:</p>
<p align="center">
<img align="center" src="imgs/lerarquivo.png">
</p>

# Compilação e Execução

O progama disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
