//
//  NSInvocation+Block.h
//  NSInvocation+Block
//
//  Created by deput on 12/11/15.
//  Copyright © 2015 deput. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSInvocation (Block)
+ (instancetype) invocationWithBlock:(id) block;
+ (instancetype) invocationWithBlockAndArguments:(id) block ,...;
@end
