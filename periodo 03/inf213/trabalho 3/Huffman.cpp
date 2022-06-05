#include "Huffman.h"

//construtor default
HuffManTree::HuffManTree(){
}

//construtor
HuffManTree::HuffManTree(int freqs[256]){
    for(int i=0;i<256;i++){ //percorre todo o vetor de frequência
        char c = i;
        if(freqs[i]!=0){//se a frequência for 0 ela pode ser dispensada porque não vai fazer diferença, já que só iremos comprimir os caracteres que existem no arquivo fonte
            pair<int,HuffmanNode*> aux;
            aux.first = freqs[i];
            aux.second = new HuffmanNode(c, freqs[i]); 
            pq.push(aux);
        }
    }
    create();
}
//construtor de cópia
HuffManTree::HuffManTree(const HuffManTree &other){
    *this = other;
}
//operador de cópia
HuffManTree & HuffManTree::operator=(const HuffManTree &other){
    if(this==&other) return *this; 
	destroy(root);
    pq = other.pq;
    create();
    
	return *this;
}
//destrutor
HuffManTree::~HuffManTree(){
    destroy(root);
}

//funcoes publicas
void HuffManTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in){
    for(int i=0;i<in.size();i++){
        MyMap<unsigned char,string>::iterator it = tabelaCodigo.find(in[i]); //procura o caracter na tabelaCodigo, se achar ele vai escrever o códígo que o representa no vetor de booleano
        if(it!=NULL) {
            for(int j=0;j<(*it).second.size();j++){
                bool aux = (*it).second[j] == '1'; //se for igual a 1 retorna 1 e se for igual a 0 retorna 0
                out.push_back(aux);
            }
        }
    }
}
void HuffManTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const{
    HuffmanNode * aux = root;
    //caso de só ter apenas um caracter, assim a raiz da arvore de Huffman é a única folha
    if(aux->isLeaf()){
        for(int i=0;i<aux->freq;i++){//vai copiar o caracter no arquivo de saida o número de frequência dele(essa informação fica armazenada no nodo) de vezes
            out.push_back(aux->elem);
        }   
    }
    //caso tenha mais de um caracter
    else{
        for(int i=0;i<in.size();i++){
            //se for
            if(aux->isLeaf()){
                out.push_back(aux->elem); //não tem utilidade usar a frequência aqui pois se for repetido o código dele será lido mais de uma vez e retornar ao mesmo lugar
                aux = root; //volta pra raiz
            }
            if(in[i] == false) aux = aux->left; //se for 0 vai ser direcionado pro filho esquerdo
            if(in[i] == true) aux = aux->right;//se for 1 vai ser direcionado pro filho esquerdo
        }
        out.push_back(aux->elem);
    }
}


//funcoes auxiliares
void HuffManTree::create(){
    int frequencia;
    pair<int,HuffmanNode*> auxPair;
    while(pq.size() != 1){ //quando a fila tiver apenas um elemento, é a árvore de Huffman
        //pego os dois caracteres com menores frequencias
        HuffmanNode * auxEsquerda = pq.top().second;
        pq.pop();
        HuffmanNode * auxDireita = pq.top().second;
        pq.pop();
        //somo as suas frequências
        frequencia = auxDireita->freq + auxEsquerda->freq;
        //faço uma subarvore contendo a raiz como a soma das frequencias e seus filhos(as futuras folhas da arvore de Huffman) como os caracteres
        HuffmanNode * rootAux = new HuffmanNode(' ', frequencia);
        auxPair.first = frequencia;
        auxPair.second = rootAux;
        rootAux->right = auxDireita;
        rootAux->left = auxEsquerda;
        //insiro a subarvore na fila de prioridade
        pq.push(auxPair);
    }
    //para o caso de ter apenas um caracter
    if(pq.size() == 1){
        root = pq.top().second;
        pq.pop();
    }
    root = pq.top().second;
    geraMap(root);
}

//função recursiva que deleta nodo a nodo
void HuffManTree::destroy(HuffmanNode *nodo){
    if(!nodo) return;
	destroy(nodo->left);
	destroy(nodo->right);
	delete nodo;
}

//usei o imprimeDFS do MySet como base já que meu objetivo é percorrer o vetor por profundidade
void HuffManTree::geraMap(HuffmanNode * rootNode){
    //cada nodo tem um codigo, porque as folhas vão possuir o código do "pai" + 0/1 dependendo se forem filhos esquerdos ou direitos(e os "pais" da folha vão possuir o código do "pai" + 0/1, não sei se foi possível entender apenas com essa explicação mas é fácil demonstrar em um desenho)
	if(!rootNode) return; //ponto de parada, se o nodo for nulo a função para
    if(rootNode->left != NULL){ //se o filho esquerdo não for vazio, pois iremos chama-lo recursivamente na funcao
        rootNode->left->codigo = rootNode->codigo + "0"; //coloco o codigo do nodo da esquerda como sendo o codigo do "pai" dele acrescentando o 0
        geraMap(rootNode->left);   
    }
    if(rootNode->right != NULL){ //se o filho direito não for vazio, pois iremos chama-lo recursivamente na funcao
        rootNode->right->codigo = rootNode->codigo + "1"; //coloco o codigo do nodo da esquerda como sendo o codigo do "pai" dele acrescentando o 0
        geraMap(rootNode->right);   
    }
    if(rootNode->isLeaf()){ //se for uma folha, temos que acrescentar o caracter e o seu respectivo codigo na nossa tabela
        pair<unsigned char,string> aux;
        aux.first = rootNode->elem;
        aux.second = rootNode->codigo;
        tabelaCodigo.insert(aux);
    }
}


//Funcoes para teste
void HuffManTree::imprimeFila(){
    while(!pq.empty()){
        cout<<pq.top().second->freq<<" ";
        pq.pop();
    }
}
void HuffManTree::imprimeBFS() const{ //um nivel por vez..
	MyQueue<HuffmanNode *> q;
	MyQueue<HuffmanNode *> u;
	if(!root) return;
	u.push(root);

	int nivel = 0;
	while(!u.empty()) {
		q = u;
		u = MyQueue<HuffmanNode *>();

		cout <<  "Nivel " << nivel++ << " : ";
		while(!q.empty()) {
			HuffmanNode * p = q.front();
			q.pop();
			cout<<p->elem<<p->freq<<" ";
			if(p->left) u.push(p->left);  
			if(p->right) u.push(p->right);
        }
		cout << endl;
    }
}