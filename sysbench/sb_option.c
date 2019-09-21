#include "sb_option.h"
#include <stdio.h>

sb_list_t options;

sb_option_t default_options[] = {
  SB_OPT("threads", "number of threads to use", "1", INT),
  SB_OPT("events", "limit for total number of events", "0", INT),
  SB_OPT("time", "limit for total execution time in seconds", "10", INT),
  SB_OPT("warmup-time", "execute events for this many seconds with statistics "
                        "disabled before the actual benchmark run with statistics enabled",
         "0", INT),
  SB_OPT("forced-shutdown",
         "number of seconds to wait after the --time limit before forcing "
         "shutdown, or 'off' to disable", "off", STRING),
  SB_OPT("thread-stack-size", "size of stack per thread", "64K", SIZE),
  SB_OPT("thread-init-timeout", "wait time in seconds for worker threads to initialize", "30", INT),
  SB_OPT("rate", "average transactions rate. 0 for unlimited rate", "0", INT),
  SB_OPT("report-interval", "periodically report intermediate statistics with "
                            "a specified interval in seconds. 0 disables intermediate reports",
         "0", INT),
  SB_OPT("report-checkpoints", "dump full statistics and reset all counters at "
                               "specified points in time. The argument is a list of comma-separated "
                               "values representing the amount of time in seconds elapsed from start "
                               "of test when report checkpoint(s) must be performed. Report "
                               "checkpoints are off by default.", "", LIST),
  SB_OPT("debug", "print more debugging info", "off", BOOL),
  SB_OPT("validate", "perform validation checks where possible", "off", BOOL),
  SB_OPT("help", "print help and exit", "off", BOOL),

  SB_OPT_END
};

sb_option_t *sb_option_get_entry(const char *name) {
  sb_list_for_each (options) {
    sb_option_t *opt = sb_list_entry(pos, sb_option_t);
    if (!strcmp(opt->name, name))
      return opt;
  }
  return NULL;
}

char *sb_option_get_value(const char *name) {
  sb_option_t *opt = sb_option_get_entry(name);
  if (!opt)
    return NULL;
  return opt->value;
}

void sb_option_set_value(const char *name, char *value) {
  sb_option_t *opt = sb_option_get_entry(name);
  if (!opt)
    return;
  opt->value = value;
}

void sb_option_init(void) {
  sb_list_init(options);
  int i = 0;
  for (; default_options[i].type != SB_ARG_TYPE_NULL; ++i)
    sb_list_add(options, default_options[i]);
}

void sb_option_parse(int argc, char *argv[]) {

}