<h1 align="center">:closed_book: Corretor ortográfico </h1>
<p align="center">
 Objetivo aqui...
 </p>
<p align="center">
<img src="https://img.shields.io/github/repo-size/jhonatancunha/corretor_ortografico" alt="">
<img src="https://img.shields.io/github/license/jhonatancunha/corretor_ortografico" alt="">
<img src="https://img.shields.io/github/last-commit/jhonatancunha/corretor_ortografico" alt="">
</p>
<br>


## :red_circle: Como Utilizar

```bash
# Clone este repositório
$ git clone https://github.com/jhonatancunha/corretor_ortografico

# Acesse a pasta do projeto no terminal/cmd
$ cd corretor_ortografico

# Execute o makefile (windows)
$ mingw32-make

# Execute o makefile (linux)
$ make

# Por fim inicie o executavel

#Windows
$ main "nome_arquivo.txt" 

#Linux
$ ./main "nome_arquivo.txt"
```

## :mag: Explicação dos Argumentos

| Argumento          | Descrição                                                                               |
| ------------------ | --------------------------------------------------------------------------------------- |
| "nome_arquivo.txt" | É o arquivo .txt que você deseja verificar se a ortografia das palavras estão corretas. |

## :camera_flash: Exemplo
```bash
#Executei passando os seguintes argumentos

#Windows
$ main "testes/default.txt"

#Linux
$ ./main "testes/default.txt"
```


Obtemos as seguintes informações como saida do algoritmo.<br />

<p align="center">
  <img src="img/exemplo_default.PNG" alt="Exemplo onde passo arquivo default.txt a fim de verificar erros de ortografia no mesmo" />
</p>
<br />

### :bulb: Comparação do texto incorreto do arquivo e sua versão correta

| STATUS    | TEXTO                                                      |
| --------- | ---------------------------------------------------------- |
| Incorreto | Eyte e um arxuiyo exkmpvo qte seva analizadu pelu corretur |
| Correto   | Este e um arquivo exemplo que sera analisado pelo corretor |

## :vertical_traffic_light: Regras Utilizadas

  ### Regra 1

  <br />
  Nesta palavra utilizaremos a técnica de alternar coringas com objetivo de encontrar qual a letra incorreta em nossa palavra. Coringas serão representador pelo caracter <i>'*'</i>, e na posição referente a ele, podemos usar qualquer letra do alfabeto até encontrar a correta.
  <br /><br />

  :mag_right: Palavra: *hoye*

  | Prefixo Procurado | Resultado |
  | ----------------- | --------- |
  | *oye              | NULL      |
  | h*ye              | NULL      |
  | ho*e              | hoje      |
  | hoy*              | NULL      |
  <br />  

  ### Regra 2

  <br />
  Utilizaremos esta regra em palavras com mais de 5 letras, onde iremos pesquisar uma palavra <i>p</i> que vá até a posição n-3 e n-2. 
  <br /><br />

  :mag_right: Palavra: *saladq*

  | Prefixo Procurado | Resultado       |
  | ----------------- | --------------- |
  | salad             | salada, saladas |
  | sala              | sala, salada    |
  <br />  


## :mortar_board: Autores

<a href="https://github.com/jhonatancunha">
 <img style="border-radius: 50%;" src="https://avatars0.githubusercontent.com/u/52831621?s=460&u=2b0cfdafeb7756176ded82c41738e773e92762b8&v=4" width="100px;" alt=""/>
<br />
 <b>Jhonatan Cunha</b></a>
 <a href="https://github.com/jhonatancunha" title="Repositorio Jhonatan"></a>

[![Gmail Badge](https://img.shields.io/badge/-jhonatancunha@alunos.utfpr.edu.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:jhonatancunha@alunos.utfpr.edu.br)](mailto:jhonatancunha@alunos.utfpr.edu.br)
<br />

<a href="https://github.com/JessePires">
 <img style="border-radius: 50%;" src="https://avatars0.githubusercontent.com/u/20424496?s=460&u=87f2870ff153ab88402d6246cb3347a46ae33fe9&v=4" width="100px;" alt=""/>
<br />
 <b>Jessé Pires</b>
 </a> <a href="https://github.com/JessePires" title="Repositorio Jessé"></a>

[![Gmail Badge](https://img.shields.io/badge/-jessepires@alunos.utfpr.edu.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:jessepires@alunos.utfpr.edu.br)](mailto:jessepires@alunos.utfpr.edu.br)

## :memo: Licença
[MIT](https://choosealicense.com/licenses/mit/)
