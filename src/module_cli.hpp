#ifndef MODULE_CLI_HPP
#define MODULE_CLI_HPP
#include <string>

using value_type = int;
using type_name = std::string;

struct RunningOptions {
  value_type number_verifications{3};
  bool help{false};
  type_name input_file;

};

bool check_file(const type_name& arquivo);

/// Returns a Running Options object filled in with the arguments passed via CLI.
RunningOptions parse_cli_arguments(int argc, char** argv);

#endif  // !MODULE_CLI_HPP
