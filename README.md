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

## Update
I attempted to add support for struct and union.
```
NSUInteger valueSizeInByte = 0;
NSUInteger align = 0;
NSGetSizeAndAlignment(argType, &valueSizeInByte, &align);
void* buffer = malloc(valueSizeInByte);
if (align == 4) {
  for (int ii = 0; ii < valueSizeInByte / align ; ii++) {
    UInt32 val = va_arg(args,UInt32);
    memcpy(((UInt32*)buffer+ii), &val, align);
  }
}else if(align == 8){
  for (int ii = 0; ii < valueSizeInByte / align ; ii++) {
    UInt64 val = va_arg(args,UInt64);
    memcpy(((UInt64*)buffer+ii), &val, align);
  }
}
[invocation setArgument:buffer atIndex:1 + i];
free(buffer);
```
Anyhow, code only worked for struct on device!
Besides, the use of `buffer` in the code snippet is not safe. Actually we can't see implementation of NSInvoation, do not know how it behaves when calling `-[NSInvoation retainArguments]`. 

In a word, I won't add this snippet before i figure it out.


