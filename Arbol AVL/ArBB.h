#include"ArBin.h"
typedef ArBin ArBB;

ArBB insordAB(Elem e, ArBB a){
    if(esvacioAB(a))
         return consAB(e,vacioAB(),vacioAB());
    else if(EsMenor(e,raiz(a)))
             return consAB(raiz(a),insordAB(e,izqAB(a)),derAB(a));
         else
             return consAB(raiz(a),izqAB(a),insordAB(e,derAB(a)));
}

Elem ElMenor(ArBB a){
	if(EsHoja(a)||esvacioAB(izqAB(a)))
		return raiz(a);
	else
		return ElMenor(izqAB(a));
}
