//
//  MD360Director.h
//  MD360Player4IOS
//
//  Created by ashqal on 16/4/7.
//  Copyright © 2016年 ashqal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MD360Program.h"
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "MDVRHeader.h"

#pragma mark MD360Director
@interface MD360Director : NSObject<IMDDestroyable>
- (instancetype)init;
- (void) shot:(MD360Program*) program;
- (void) reset;
- (void) updateProjection:(int)width height:(int)height;
- (void) updateProjectionNearScale:(float)scale;
- (void) updateProjection;
- (void) updateSensorMatrix:(GLKMatrix4)sensor;
- (void) updateTouch:(float)distX distY:(int)distY;

- (float) getRatio;
- (float) getNear;

- (void) setProjection:(GLKMatrix4)project;
- (void) setLookX:(float)lookX;
- (void) setEyeX:(float)eyeX;
- (void) setAngleX:(float)angleX;
- (void) setAngleY:(float)angleY;
- (void) setup;

@end

#pragma mark MD360DirectorFactory
@protocol MD360DirectorFactory <NSObject>
@required
- (MD360Director*) createDirector:(int) index;
@end

#pragma mark MD360DefaultDirectorFactory
@interface MD360DefaultDirectorFactory : NSObject<MD360DirectorFactory>

@end

#pragma mark MD360OrthogonalDirectorFactory
@interface MD360OrthogonalDirectorFactory : NSObject<MD360DirectorFactory>

@end



