cc_binary(
  name = "main",
  srcs = [
    "main.cc",
  ],
  deps = [
    "//:factory_include",
    "//:consumer_include",
    "//:production_include"
  ],
  linkopts = [
    "-lpthread"
  ]
)

cc_library(
  name = "factory_include",
  hdrs = [
    "factory.h",
  ],
  srcs = [
    "factory.cc",
  ],
  deps = [
    "//:production_include"
  ]
)

cc_library(
  name = "consumer_include",
  hdrs = [
    "consumer.h",
  ],
  srcs = [
    "consumer.cc",
  ],
  deps = [
    "//:production_include"
  ]
)

cc_library(
  name = "production_include",
  hdrs = ["production.h"],
)