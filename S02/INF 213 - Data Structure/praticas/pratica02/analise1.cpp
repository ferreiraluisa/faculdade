
//Exemplo de analise de complexidade:
//Note que simplificamos ao máximo na notacao O (removendo o n, ja que O(n^2 +n) = O(n^2), pois a parte quadratica "pesa mais")
//Complexidade: O(n^2 + m + n) = O(n^2 + m)

//O(n^2 + m)
void funcao1(int n, int m) {
	for(int i=0;i<n;i++)//O(n^2)
		for(int j=0;j<n;j++)
			ct *= j;
	
	for(int k=0;k<m;k++)//O(m)
		ct += 10;

	for(int k=0;k<n;k++) //O(n)
		ct += 10;
}
//O(n^3 + m)
void funcao2(int n, int m) {
	for(int i=0;i<n;i++) //O(n^2)
		for(int j=0;j<n;j++)
			ct *= j;
	
	for(int k=0;k<m;k++) //O(int * m)
		funcao1(30,40);

	for(int k=0;k<n;k++) //O(n * (n^2 + 200)) = n^3
		funcao1(n,200);
}
//O(nk + m)
void funcao3(int n, int m, int k) {
	for(int i=0;i<n;i++) //O(n*k)
		for(int j=0;j<k;j++)
			ct *= m;

	for(int i=0;i<m/100000;i++) { //O(m)
		ct += k;
	}
}
//O(n^2)
void funcao4(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) { //O(n^2)
		if(v[i]%2==0) break; //pior caso: todos elementos sejam impares
		for(int j=0;j<n;j++) {
			ct += v[i] + v[j];
		}
	}
}
//O(n)
void funcao5(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		//O(2n)
		for(int j=0;j<n;j++) {
			ct++;
			if(ct%2==0) break;
		}
	}
}
//O(n^2)
void funcao6(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<n;j++) {
			ct+= log(n);
		}
	}
}
//O(n^2)
void funcao7(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=1;i<n;i++) {		
		for(int j=i;j<n;j++) {
			ct+= log(n);
		}
	}
}
//O(nlog(m))
void funcao8(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<log(m);j++) {
			ct += sin(k);
		}
	}
}

//Responda (alem de analisar a complexidade): o que essa funcao faz? Calcula o log na base 10
//O(logn)
void funcao9(int n) {
	if(n==0) return 0;
	return funcao9(n/10)+1;
}
//O(log(n) + log(m))
void funcao10(int n, int m, int k, int v[]) {
	if(n==0 && m==0) return 1;
	if(n==0) return funcao10(n,m/2,k,v);
	else return funcao10(n/2,m,k,v);
}
//O(n * sum v[i])
void funcao11(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<v[i];j++) {
			ct += k;
		}
	}
}
//O(n^2)
int funcao12(int n) {
    int ans = 0;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}
//O(ufv)
double funcao13(int v,int u, int f) {
	double ans = 0;
	for(int i=0;i<u;i++) {
	   for(int j=0;j<v;j++) ans -= log(i*j);
	   ans += log(u+i);
	   for(int j2=0;j2<f/2;j2++)
		for(int k=v/2;k<v;k++)
	   		ans += log(j2*k); 
	}
	return ans;
}


//Analise a complexidade de melhor e pior caso dessa função
//R: Melhor caso: o primeiro elemento ser igual ao numero m, logo a função tem complexidade O(1)
//Pior caso: não ter nenhum elemento no array igual ao numero m, logo a função tem complexidade O(n)
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem
//O(1) melhor caso
//O(n) pior caso
void funcao14(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(v[i]==m)
			return i;		
	}
	return -1;
}

//Analise a complexidade de melhor e pior caso dessa função
//R: Melhor caso: o n ser igual a 5, logo a complexidade é O(1)
//Pior caso: o w ser um numero impar, pois nunca sera um multiplo de 10, logo complexidade é O(n^3)
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem
//O(1) melhor caso
//O(n^3) pior caso
int funcao15(int n, int w) {
    int ans = w;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//O(mn)
int funcao16(int n, int w) {
    double ans = w;
    for(int i=0;i<n;i++) 
    	for(int j=0;j<n;n--) 
    		for(int k=0;k<m;k++)//tomando m como parametro da funcao
    			ans += 3.14;
    	
    
    return ans;
}