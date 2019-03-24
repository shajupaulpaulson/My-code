/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <functional>

using namespace std;

int main (){
	uniform_int_distribution<int> dist(0, 1000);
	mt19937 engine;
	default_random_engine gen;
	auto generator = bind(dist, engine);
	uniform_real_distribution<double> dist2(0.0,5.0);
	bernoulli_distribution dist3(4.4);
	cout << "Random number from differnt function : \n"\
	"uniform_int_distribution : " << dist(engine) << "\n" \
	"generator : " << generator() << "\n"\
	"uniform_real_distribution : " << dist2(engine)  << "\n"\
	"bernoulli_distribution : " << dist3(engine) << "\n"\
	"uniform_int_distribution mt19337: " << dist(engine) << "\n"\
	"uniform_int_distribution default random engine: " << dist(gen) <<"\n" \
	;

	return 0;
}

/*
Differnet distrubution techniques:
uniform_int_distribution,
uniform_real_distribution,
bernoulli_distribution,
binomial_distribution,
geometric_distribution,
negative_binomial_distribution,
poisson_distribution,
exponential_distribution,
gamma_distribution,
weibull_distribution,
extreme_value_distribution,
normal_distribution,
lognormal_distribution,
chi_squared_distribution,
cauchy_distribution,
fisher_f_distribution,
student_t_distribution,
discrete_distribution,
piecewise_constant_distribution and
piecewise_linear_distribution.
http://www.cplusplus.com/reference/random/binomial_distribution/
*/
