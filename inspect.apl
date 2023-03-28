include "io.apl";

int main(){
	string var value_to_inspect;
	inp(value_to_inspect);
	inspect(value_to_inspect){
		i as int:{
			inspect(i){
				is in [0,2]:{
					return 5;
				}
				is >=3:{
					return 4; 
				}
				is _:{
					return 3;
				}
			}
		}
		is "":{
			return 2;
		}
		is _:{
			return 1;
		}
	}
}