#include "Huffman.h"

//construtor default
HuffManTree::HuffManTree(){

}

//construtor
HuffManTree::HuffManTree(int freqs[256]){
    for(int i=0;i<256;i++){
        char c = i;
        if(freqs[i]!=0){
            pair<int,HuffmanNode*> aux;
            aux.first = freqs[i];
            aux.second = new HuffmanNode(c, freqs[i]); 
            pq.push(aux);
        }
    }
    create();
    geraMap(root);
}
//construtor de cópia
HuffManTree::HuffManTree(const HuffManTree &other){

}
//operador de cópia
// HuffManTree & HuffManTree::operator=(const HuffManTree &){

// }
//destrutor
HuffManTree::~HuffManTree(){
    destroy(root);
}

//funcoes publicas
void HuffManTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in){
    for(int i=0;i<in.size();i++){
        MyMap<unsigned char,string>::iterator it = tabelaCodigo.find(in[i]);
        if(it!=NULL) {
            for(int j=0;j<(*it).second.size();j++){
                bool aux = (*it).second[j] == '1';
                out.push_back(aux);
            }
        }
    }
}
void HuffManTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const{
    HuffmanNode * aux = root;
    if(aux->isLeaf()){
        for(int i=0;i<aux->freq;i++){
            out.push_back(aux->elem);
        }   
    }
    else{
        for(int i=0;i<in.size();i++){
            if(aux->isLeaf()){
                out.push_back(aux->elem);
                aux = root;
        }
        if(in[i] == false) aux = aux->left;
        if(in[i] == true) aux = aux->right;
        }
        out.push_back(aux->elem);
    }
}


//funcoes auxiliares
void HuffManTree::create(){
    int frequencia;
    pair<int,HuffmanNode*> auxPair;
    while(pq.size() != 1){
        HuffmanNode * auxEsquerda = pq.top().second;
        pq.pop();
        HuffmanNode * auxDireita = pq.top().second;
        pq.pop();
        frequencia = auxDireita->freq + auxEsquerda->freq;
        HuffmanNode * rootAux = new HuffmanNode('!', frequencia);
        auxPair.first = frequencia;
        auxPair.second = rootAux;
        rootAux->right = auxDireita;
        rootAux->left = auxEsquerda;
        pq.push(auxPair);
    }
    if(pq.size() == 1){
        root = pq.top().second;
        pq.pop();
    }
    root = pq.top().second;
}

void HuffManTree::destroy(HuffmanNode *nodo){
    if(!nodo) return;
	destroy(nodo->left);
	destroy(nodo->right);
	delete nodo;
}

void HuffManTree::geraMap(HuffmanNode * rootNode){
	if(!rootNode) return; //ponto de parada, se o nodo for nulo a função para
    if(rootNode->left != NULL){ //se o filho esquerdo não for vazio, pois iremos chama-lo recursivamente na funcao
        rootNode->left->codigo = rootNode->codigo + "0"; //coloco o codigo do nodo da esquerda como sendo o codigo do "pai" dele acrescentando o 0
        geraMap(rootNode->left);   
    }
    if(rootNode->right != NULL){
        rootNode->right->codigo = rootNode->codigo + "1"; //coloco o codigo do nodo da esquerda como sendo o codigo do "pai" dele acrescentando o 0
        geraMap(rootNode->right);   
    }
    if(rootNode->isLeaf()){ //se for uma folha, temos que acrescentar o caracter e o seu respectivo codigo na nossa tabela
        pair<unsigned char,string> aux;
        aux.first = rootNode->elem;
        aux.second = rootNode->codigo;
        //cout<<aux.first<<" "<<aux.second<<endl;
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