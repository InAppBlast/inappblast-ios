//
//  PushPanel.h
//  PushPanel
//
//  Copyright (c) 2014 Yumixo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    PushPanelLogLevelNone       = 0,
    PushPanelLogLevelOnlyErrors = 1,
    PushPanelLogLevelAll        = 2,
} PushPanelLogLevel;

@interface PushPanel : NSObject

+ (PushPanel *) initSharedInstanceWithToken:(NSString *)token;
+ (PushPanel *) sharedInstance;
+ (void) setLogLevel:(PushPanelLogLevel)logLevel;
+ (PushPanelLogLevel) getLogLevel;
- (void) registerUser:(NSString *)uniqueUserId;
- (void) setUserProperties:(NSDictionary *)userProperties;
- (void) incUserProperties:(NSDictionary *)userProperties;
- (void) event:(NSString *)eventName;
- (NSString *) currentUserId;
- (void) logoutUser;

@end
