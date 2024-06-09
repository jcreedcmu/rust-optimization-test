run: example-rust
	LD_LIBRARY_PATH=./cost-function/target/debug/ ./example-rust

example-rust: example-rust.cpp cost-function/src/lib.rs
	cd cost-function && cargo build
	g++ example-rust.cpp -lcost_function -L./cost-function/target/debug -o $@
