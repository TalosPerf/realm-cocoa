////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Realm/Realm.h>

#import "RLMServerUtil.h"

@interface RLMRealmConfiguration (Server)

NS_ASSUME_NONNULL_BEGIN

/**
 Set the error handler callback for the Realm at this given path. Note that only the error handler set when the Realm is
 first bound to the Realm Object Server will be registered; changing the callback after the Realm has been bound will
 have no effect.
 */
- (void)setErrorHandler:(nullable RLMErrorReportingBlock)errorHandler;

/**
 Set the configuration up to define a Realm that is synced with a Realm Object Server. Upon opening a Realm, a
 connection will automatically be established with the server (if necessary), and synchronization will begin.

 @see `-setObjectServerPath:forUser:callback:`
 */
- (void)setObjectServerPath:(nullable RLMServerPath)path forUser:(nullable RLMUser *)user;

/**
 Set the configuration up to define a Realm that is synced with a Realm Object Server. Upon opening a Realm, a
 connection will automatically be established with the server (if necessary), and synchronization will begin. Once the
 Realm is connected to the Realm Object Server, an optional callback can be executed.

 @param path The path on the Realm Object Server to the remote Realm. This can be an unresolved path (e.g.
             `/~/path/to/realm`), or a resolved path (e.g. `/someuser/path/to/realm`). Do not try to resolve a path
             yourself. Set this to `nil` if the Realm should not be synced.
 @param user A `RLMUser` instance. This user must be the anonymous user, or it must be a properly configured user that
             has already successfully logged in.
 @param callback An optional block that will be invoked once the Realm has successfully connected to the Realm Object
                 Server. It is passed in an `NSError` argument that is `nil` if the connection was successful.
 */
- (void)setObjectServerPath:(nullable RLMServerPath)path
                    forUser:(nullable RLMUser *)user
                   callback:(nullable RLMErrorReportingBlock)callback;

NS_ASSUME_NONNULL_END

@end
