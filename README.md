# Batalha Naval: Simulação com Tabuleiro e Habilidades Especiais

Este projeto foi desenvolvido como parte da disciplina **Introdução à Programação de Computadores** na **Estácio de Sá**. Ele simula um tabuleiro de Batalha Naval, com navios posicionados estrategicamente e habilidades especiais que influenciam áreas específicas no tabuleiro.

## 🚀 Funcionalidades

1. **Criação de um tabuleiro 10x10**:
   - O tabuleiro é inicializado com valores `0`, representando células vazias.

2. **Posicionamento dos navios**:
   - Navios são posicionados nas seguintes formas:
     - **Vertical**
     - **Horizontal**
     - **Diagonal (subindo e descendo)**
   - Cada navio é representado pelo valor `3`.

3. **Uso de habilidades especiais**:
   - Habilidades especiais são implementadas em três formas:
     - **Cone**: Afeta células cônicas a partir de um ponto central.
     - **Cruz**: Afeta células em formato de cruz a partir de um ponto central.
     - **Octaedro**: Afeta células em padrões mais amplos e simétricos.
   - A habilidade básica é representada pelo valor `5`.
   - Células sobrepostas a um navio (raio de influência da habilidade) são representadas por `1`.

4. **Exibição do tabuleiro final**:
   - O tabuleiro é exibido com:
     - Colunas rotuladas com letras (`A` a `J`).
     - Linhas numeradas (`1` a `10`).

## 📋 Regras e Lógica do Jogo

- **Navios**:
  - O posicionamento dos navios leva em conta índices centrais previamente configurados.
  - Tipos de posicionamento:
    - Vertical (para baixo).
    - Horizontal (para a direita).
    - Diagonal subindo e descendo.

- **Habilidades especiais**:
  - As habilidades verificam se há um navio na área de influência. Se houver, o valor da célula será alterado para `1`. Caso contrário, será `5`.

- **Validação de limites**:
  - O código garante que nenhum navio ou habilidade ultrapassará as dimensões do tabuleiro.


### Principais seções
1. **Inicialização do Tabuleiro**:
   - A matriz principal `tabuleiro` é preenchida com valores `0`.

2. **Correção de Coordenadas**:
   - As coordenadas fornecidas (do tipo `char`) são ajustadas para índices baseados em `0`.

3. **Posicionamento**:
   - Navios e habilidades são posicionados no tabuleiro utilizando loops `for`.

4. **Impressão**:
   - O tabuleiro é exibido ao final, com linhas e colunas rotuladas.


## ✨ Créditos

- **Aluno**: Jairçon Freitas Sodré Pereira Júnior.
- **Disciplina**: Introdução à Programação de Computadores.
- **Nível**: Mestre.

---

Se precisar de ajustes ou detalhes específicos, é só avisar! 😊
