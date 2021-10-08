#include "crow_all.h"

int multiply_by_two(int x) {
  return x * 2;
}

std::string reverse_string(std::string base) {
    std::string result = "";

    for (int i = base.length() - 1; i >= 0; i--) {
        result.push_back(base[i]);
    }

    return result;
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/factorial/<int>")([](int x){
	 int factorial = 1;
	 for (int i = x; i > 1; i--) {
	   factorial *= i;
	 }
	 return std::to_string(factorial) + "\n";
					});

	CROW_ROUTE(app, "/reverse").methods(crow::HTTPMethod::GET, crow::HTTPMethod::POST)([](const crow::request& req) {
		return reverse_string(req.body) + "\n";
	});

    app.port(18080).multithreaded().run();
}