// RCVerification.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include "tools.cpp"

int main(int argc, _TCHAR* argv[])
{
	Vector cache_pos = Vector(80.0, 0.0, 10.0);
	Vector sample_pos = Vector(80.0, 5.0, 0.0);
	REAL *contrib = new REAL[max_SH_order * max_SH_order];
	Sample_contribution(cache_pos, sample_pos, contrib);

	cout << contrib[62] << endl;
	
	delete[] contrib;
	int whatever;
	cin >> whatever;
	return 0;
}



