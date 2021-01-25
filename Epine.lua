local cc = require "epine-cc"

vars {
    NAME = "libmy.a";
    CFLAGS = "-Wall -Wextra -pedantic";
}

-- targets
local libmy = cc.static(vars.NAME)
{
    files = { find "./src/*.c" };
    includes = { "./include" };
    defines = {
        "MY_ALLOW_FUN_MALLOC", "MY_ALLOW_FUN_FREE", "MY_ALLOW_FUN_CALLOC",
        "MY_ALLOW_FUN_MEMMOVE", "MY_ALLOW_FUN_MEMCPY", "MY_ALLOW_FUN_MEMSET",
        "MY_ALLOW_FUN_WRITE", "MY_ALLOW_FUN_READ", "MY_ALLOW_FUN_OPEN",
        "MY_ALLOW_FUN_CLOSE", "MY_ALLOW_FUN_RAND", "MY_ALLOW_FUN_RAND_R",
        "MY_ALLOW_FUN_SRAND", "MY_ALLOW_FUN_TIME",
    };
}

local tests = cc.binary("tests.out")
{
    files = { find "./tests/*.c" };
    uses = { libmy, cc.lib "criterion" };
}

action("tests_run")
{
    needs = { tests };
    run = { "./tests.out $(ARGS)" };
}

default(libmy)
