# NSInvocation-Block

## Objective
NSInvocation-Block is a NSInvocation category to create NSInvocation with block

## Usage
Given
```objc
void (^myBlock)(id, NSString*, NSArray*) = ^(id obj1, NSString* name, NSArray* array) {
  NSLog(@"%@",@"Hey!");
};
```
We can create an invocation:
```objc
NSInvocation* inv = [NSInvocation invocationWithBlock:myBlock];
```
Or with arguments:

```objc
NSInvocation* inv = [NSInvocation invocationWithBlockAndArguments:myBlock,[NSObject new],@"Hello",@[@1,@2,@3]];
```

## Known issues
1. Arguments of struct, union or C-style array type are not supported yet.

