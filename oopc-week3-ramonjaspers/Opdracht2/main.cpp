
#include <iostream>
int main(int argc, char **argv) {
	/**
	class vehicle { . . . };
	class car : public vehicle { . . . };
	class train : public vehicle { . . . };
	class intercity : public train { . . . };

	void travel( vehicle & v );
	void ovchipkaart( train & t );
	void file( car & c );

	car        batmobiel;
	intercity  utr_amst;
	train      ICE;

	file( batmobiel );        // 1
	ovchipkaart( utr_amst );  // 2
	file( ICE )               // 3
	ovchipkaart( batmobiel )  // 4
	travel( utr_amst )        // 5
	travel( batmobiel )       // 6

	intercity & ref7   = utr_amst;          // 7
	car       & ref8   = utr_amst;          // 8
	train     & ref9   = utr_amst;          // 9
	train     & ref10  = batmobiel;         // 10
	intercity & ref11  = batmobiel;         // 11
	intercity & ref12  = ICE;               // 12

	 1: correct, batmobiel is is een car en file heeft een car nodig
	 2: correct, utr_amst is eenn intercity en een intercity is een public train en ovchipkaart eist een train.
	 3: error, ICE is geen car.
	 4: error, batmobiel is geen train.
	 5: correct, utr_amst is een vehicle.
	 6: correct, batmobiel is een vehicle.

	 7: correct, hier word gerefereerd naar de goede type klasse.
	 8: error, hier wordt gerefereerd naar het foute type klasse.
	 9: correct, intercity is eenpublic train
	 10: error, batmobiel is geen train.
	 11: error, batmobiel is geen train/intercity.
	 12: error, onmogelijk om van van intercity naar trein te verwijzen

	 **/
}
