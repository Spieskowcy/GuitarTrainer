protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS track.proto)
add_library(track ${PROTO_HDRS} ${PROTO_SRCS})
