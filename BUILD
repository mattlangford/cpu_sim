cc_library(
    name = "logging",
    hdrs = ["logging.hh"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "memory",
    srcs = ["memory.cc"],
    hdrs = ["memory.hh"],
)

cc_library(
    name = "instructions",
    hdrs = ["instructions.hh"],
    deps = [":logging"],
)

cc_library(
    name = "cpu",
    srcs = ["cpu.cc"],
    hdrs = ["cpu.hh"],
    deps = [":memory",
            ":instructions",
            ":logging"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "assemble",
    srcs = ["assemble.cc"],
    hdrs = ["assemble.hh"],
    deps = [":instructions",
            ":memory"],
    visibility = ["//visibility:public"]
)
