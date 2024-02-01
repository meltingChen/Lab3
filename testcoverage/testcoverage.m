//
//  Test.m
//  Test
//
//  Created by 陳肜樺 on 2/1/24.
//

#import <XCTest/XCTest.h>
#include "run.hpp"
@interface Test : XCTestCase
@end

@implementation Test
- (void)testAll {
if (!run_tests()) XCTFail(@"failed");
}
@end
