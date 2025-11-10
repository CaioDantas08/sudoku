#include "module_cli.hpp"
#include <fstream>
/// Returns a Running Options object filled in with the arguments passed via CLI.



  bool check_file(const type_name& name_file){
    std::ifstream input_file(name_file);
    return input_file.is_open();
  }

RunningOptions parse_cli_arguments(int argc, char** argv) {
  RunningOptions run_opt;

  for(value_type i{1};i<argc;i++){

    type_name argumento = argv[i];

    if(argumento == "-c" && ((i+1) < argc)){
      try{
        value_type cobaia = std::stoi(argv[i+1]);
        if(cobaia < 0){
          std::cerr << "Number must be positive\n";
          exit(EXIT_FAILURE);
        }
        run_opt.number_verifications = cobaia;
        i++;
      }catch(...){
        std::cerr << "Error: Invalid number for -c option\n";
        exit(EXIT_FAILURE);
      }

    }
    else if(argumento == "-h") run_opt.help = true;
    else if(check_file(argumento)) run_opt.input_file = argumento;

    else{
      std::cerr << "Error: Invalid argument or file not found: " << argumento << "\n";
      exit(EXIT_FAILURE);
    }
    

  }

  if(run_opt.input_file.empty()) run_opt.input_file = "puzzles.txt";

  return run_opt;
}
