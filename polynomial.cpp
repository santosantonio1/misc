#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class polynomial{
    public:
        vector<double> coefficients;
        int degree;
        polynomial(int d=0, vector<double> c = {}){
            degree = d;
            coefficients = c;
        }
        bool operator>(polynomial &p) {
          return degree>p.degree;   
        }
        bool operator==(polynomial &p) {
            return coefficients == p.coefficients && degree == p.degree;
        }
        polynomial operator+(polynomial &p) {
            polynomial P;
            P.degree = max(degree,p.degree);
            if(degree>p.degree) {
                int i;
                for(i=0;i<p.coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]+p.coefficients[i]);
                for(;i<coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]);
            }
            else if(degree<p.degree){
                int i;
                for(int i=0; i<coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]+p.coefficients[i]);
                for(;i<p.coefficients.size();i++)
                    P.coefficients.push_back(p.coefficients[i]);
            }
            else
                for(int i=0; i<coefficients.size();i++)
                P.coefficients.push_back(coefficients[i]+p.coefficients[i]);
                
                return P;
        }
        polynomial operator-(polynomial &p) {
            polynomial P;
            P.degree = max(degree,p.degree);
            if(degree>p.degree) {
                int i;
                for(i=0;i<p.coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]-p.coefficients[i]);
                for(;i<coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]);
            }
            else if(degree<p.degree){
                int i;
                for(int i=0; i<coefficients.size();i++)
                    P.coefficients.push_back(coefficients[i]-p.coefficients[i]);
                for(;i<p.coefficients.size();i++)
                    P.coefficients.push_back(p.coefficients[i]);
            }
            else
                for(int i=0; i<coefficients.size();i++)
                P.coefficients.push_back(coefficients[i]-p.coefficients[i]);
                
                return P;
        }
        // polynomial operator*(polynomial &p) {}
        // polynomial operator/(polynomial &p) {}
        // polynomial operator%(polynomial &p) {}
        polynomial differentiate(polynomial &p) {
            polynomial P;
            P.degree = p.degree - 1;
            for(int i=0;i<p.coefficients.size();i++)
                P.coefficients.push_back(p.coefficients[i+1]*i+1);
            
            return P;
        }
        polynomial integrate(polynomial &p) {
            polynomial P;
            P.degree = p.degree + 1;
            P.coefficients.push_back(0);
            for(int i=0; i<p.coefficients.size(); i++)
            P.coefficients.push_back(p.coefficients[i]/(i+1));
            return P;
        } 
        double integral(double low, double high) {
            double sum = 0.0;
            for(int i=0; i<coefficients.size(); i++){
                double c = coefficients[i]/(i+1);
                sum +=  c*pow(high,i+1) - c*pow(low,i+1);
            }
            return sum;
        }
        double delta() {
            if(degree == 2) return pow(coefficients[1],2) - 4*coefficients[2]*coefficients[0];
            return 0;
        }
        double xv() {
            if(degree == 2) return (-1)*coefficients[1]/(2*coefficients[2]);
            return 0;
        };
        double yv() {
            if(degree == 2) return (-1)*delta()/(4*coefficients[2]);
            return 0;
        }
        vector<double> roots() {
            vector<double> r;
            if(degree == 2) {
                if(delta()>=0) {
                    r.push_back((-1)*(coefficients[1]+sqrt(delta()))/((2*coefficients[2])));
                    r.push_back((-1)*(coefficients[1]-sqrt(delta()))/((2*coefficients[2])));
                    return r;
                }
            }
            return r={};            
        }
        void print() {
            for(int i=0; i<coefficients.size(); i++)
            cout << coefficients[i] << " ";
        }
};

int main() {
    vector<double> c = {0,2};
    polynomial A(1,c);
    //A.print();
    cout << A.integral(10,13);
    return 0;
}


