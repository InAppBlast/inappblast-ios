//
//  InAppBlast.h
//  InAppBlast
//
//  Copyright (c) 2014 InAppBlast Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    InAppBlastLogLevelNone       = 0,
    InAppBlastLogLevelOnlyErrors = 1,
    InAppBlastLogLevelAll        = 2,
} InAppBlastLogLevel;

@interface InAppBlast : NSObject

+ (InAppBlast *) initSharedInstanceWithToken:(NSString *)token;
+ (InAppBlast *) sharedInstance;
+ (void) setLogLevel:(InAppBlastLogLevel)logLevel;
+ (InAppBlastLogLevel) getLogLevel;
+ (void) logError:(NSString *)message;
+ (void) logOther:(NSString *)message;
+ (void) setExternalLogBlock:(void (^)(NSString * message))logBlock;
- (void) registerUser:(NSString *)uniqueUserId;
- (void) setUserProperties:(NSDictionary *)userProperties;
- (void) incUserProperties:(NSDictionary *)userProperties;
- (void) event:(NSString *)eventName properties:(NSDictionary *)properties;
- (NSString *) currentUserId;
- (void) logoutUser;

@end
