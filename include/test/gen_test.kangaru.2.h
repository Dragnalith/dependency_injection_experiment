#pragma once
#include "gen_test.h"
#include <kangaru/kangaru.hpp>
struct MyClass_2_0Service : kgr::single_service<MyClass_2_0> {};
auto service_map(MyClass_2_0 const&) -> MyClass_2_0Service;
struct MyClass_2_1Service : kgr::single_service<MyClass_2_1> {};
auto service_map(MyClass_2_1 const&) -> MyClass_2_1Service;
struct MyClass_2_2Service : kgr::single_service<MyClass_2_2> {};
auto service_map(MyClass_2_2 const&) -> MyClass_2_2Service;
struct MyClass_1_0Service : kgr::single_service<MyClass_1_0, kgr::dependency<MyClass_2_0Service,MyClass_2_1Service>> {};
auto service_map(MyClass_1_0 const&) -> MyClass_1_0Service;
struct MyClass_1_1Service : kgr::single_service<MyClass_1_1, kgr::dependency<MyClass_2_1Service,MyClass_2_2Service>> {};
auto service_map(MyClass_1_1 const&) -> MyClass_1_1Service;
struct MyClass_0_0Service : kgr::single_service<MyClass_0_0, kgr::dependency<MyClass_1_0Service,MyClass_1_1Service>> {};
auto service_map(MyClass_0_0 const&) -> MyClass_0_0Service;
