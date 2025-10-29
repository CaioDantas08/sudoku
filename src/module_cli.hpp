#ifndef MODULE_CLI_HPP
#define MODULE_CLI_HPP

struct RunningOptions {
  // TODO: add running options here.
};

/// Returns a Running Options object filled in with the arguments passed via CLI.
RunningOptions parse_cli_arguments(int argc, char** argv);

#endif  // !MODULE_CLI_HPP
