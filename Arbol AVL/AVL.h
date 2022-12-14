#include"ArBB.h"
typedef ArBB AVL;

int absoluto(int a){
    if(a<0)
        return -a;
    else
        return a;
}
int EsAVL(AVL a){
  return esvacioAB(a)||
  ((absoluto(Altura(izqAB(a))-Altura(derAB(a)))<=1) &&
               (EsAVL(izqAB(a)))&&(EsAVL(derAB(a))));
}

int FactBal(AVL a){return Altura(izqAB(a))-Altura(derAB(a));}

AVL rotaDer(ArBB a){
    return consAB(raiz(izqAB(a)),izqAB(izqAB(a)),
                consAB(raiz(a),derAB(izqAB(a)),derAB(a)));
}
AVL rotaIzq(ArBB a){
    return consAB(raiz(derAB(a)),consAB(raiz(a),izqAB(a),izqAB(derAB(a))),
                derAB(derAB(a)));
}

AVL rotaDerIzq(ArBB a){
     return rotaDer(consAB(raiz(a),rotaIzq(izqAB(a)),derAB(a)));
}

AVL rotaIzqDer(ArBB a){
     return rotaIzq(consAB(raiz(a),izqAB(a),rotaDer(derAB(a))));
}

AVL HazAVL(ArBB a){
	if(absoluto(FactBal(a))){
		if(EsAVL(izqAB(a))&&EsAVL(derAB(a))){
			if(FactBal(a)>1){
				if(FactBal(izqAB(a))>0)
					a = rotaDer(a);
				else
					a = rotaDerIzq(a);
			}else{
				if(FactBal(derAB(a))<0)
					a = rotaIzq(a);
				else
					a = rotaIzqDer(a);				
			}
		}else{
			if(EsAVL(izqAB(a)))
				a = consAB(raiz(a),izqAB(a), HazAVL(derAB(a)));
			else if(EsAVL(derAB(a)))
				a = consAB(raiz(a),HazAVL(izqAB(a)), derAB(a));
		}
	}else{
		if(EsAVL(izqAB(a)))
			a = consAB(raiz(a),izqAB(a), HazAVL(derAB(a)));
		else if(EsAVL(derAB(a)))
			a = consAB(raiz(a),HazAVL(izqAB(a)), derAB(a));
	}
	
	return a;
}

AVL InsAVL(Elem e, AVL a){
      a=insordAB(e,a);
      if(EsAVL(a))
         return a;
      else
         return HazAVL(a);
}

ArBB BorraAVL(Elem e, ArBB a){
	if(EsIgual(e,raiz(a))){
		if(EsHoja(a))
			return vacioAB();
		else if(esvacioAB(izqAB(a)))
			return derAB(a);
		else if(esvacioAB(derAB(a)))
			return izqAB(a);
		else
			return consAB(ElMenor(derAB(a)), izqAB(a),
					BorraAVL(ElMenor(derAB(a)),derAB(a)));	
	}else if(EsMenor(e,raiz(a)))
		return consAB(raiz(a),BorraAVL(e, izqAB(a)),derAB(a));	
	else
		return consAB(raiz(a), izqAB(a), BorraAVL(e, derAB(a)));
}

AVL ElimAVL(Elem e, ArBB a){
	a=BorraAVL(e,a);
      if(EsAVL(a))
         return a;
      else
         return HazAVL(a);
}
