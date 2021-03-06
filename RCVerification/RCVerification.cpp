// RCVerification.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include "tools.h"



int main(int argc, _TCHAR* argv[])
{
	Vector cache_pos = Vector(50.0, 0.0, 50.0);
	//Vector sample_pos = Vector(75.0, 5.0, 0.0);
	//REAL *contrib = new REAL[max_SH_order * max_SH_order];
	//Sample_contribution(cache_pos, sample_pos, contrib);

	//cout << contrib[61] << endl;

	//Sample_contribution_GradX(cache_pos, sample_pos, contrib);


	//cout << contrib[61] << endl;


	REAL lower_bound[2];
	REAL upper_bound[2];

	lower_bound[0] = 0.0;
	lower_bound[1] = 0.0;

	upper_bound[0] = 100.0;
	upper_bound[1] = 100.0;
	
	srand (time(NULL));

	for(int i = 0 ; i < 10 ; i++){
		UniformSurfaceSampler *sampler = new UniformSurfaceSampler(lower_bound, upper_bound);
		//ConstantIntegrand *integrand = new ConstantIntegrand();
		ContributionIntegrand *integrand_plus = new ContributionIntegrand(cache_pos+ Vector(1.0, 0.0, 0.0) * delta,  5, 4);
		ContributionIntegrand *integrand_minor = new ContributionIntegrand(cache_pos - Vector(1.0, 0.0, 0.0) * delta,  5, 4);
		GradXContributionIntegrand *integrand_grad = new GradXContributionIntegrand(cache_pos, 5, 4);
		Integration_MC<Vector> integrationMC_plus = Integration_MC<Vector>(sampler, integrand_plus, 100000);
		Integration_MC<Vector> integrationMC_minor = Integration_MC<Vector>(sampler, integrand_minor, 100000);
		Integration_MC<Vector> integrationMC_grad = Integration_MC<Vector>(sampler, integrand_grad, 100000);

		REAL coef_plus = integrationMC_plus.Run();
		REAL coef_minor = integrationMC_minor.Run();
		REAL out1 = (coef_plus - coef_minor)/(2.0 * delta);
		REAL out2 = integrationMC_grad.Run();
		 
		/*cout << coef_plus << endl;
		cout << coef_minor << endl;*/
		cout <<"Finte difference: " << out1 <<"   AN: "<< out2 <<endl;
	}

	//cout << outttt << endl;


	//delete[] contrib;
	int whatever;
	cin >> whatever;
	return 0;
}



