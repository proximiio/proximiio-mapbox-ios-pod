// Generated by Apple Swift version 5.2.4 (swiftlang-1103.0.32.9 clang-1103.0.32.53)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import AVFoundation;
@import CoreLocation;
@import Foundation;
@import Mapbox;
@import ObjectiveC;
@import Proximiio;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="ProximiioMapbox",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif











@class NSCoder;

SWIFT_CLASS("_TtC15ProximiioMapbox13PIOAnnotation")
@interface PIOAnnotation : MGLPointAnnotation
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox15PIOAudioManager")
@interface PIOAudioManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (void)playerItemDidFinishPlaying:(NSNotification * _Nonnull)notification;
@end

@class AVSpeechSynthesizer;

@interface PIOAudioManager (SWIFT_EXTENSION(ProximiioMapbox)) <AVSpeechSynthesizerDelegate>
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer didStartSpeechUtterance:(AVSpeechUtterance * _Nonnull)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer didFinishSpeechUtterance:(AVSpeechUtterance * _Nonnull)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer didPauseSpeechUtterance:(AVSpeechUtterance * _Nonnull)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer didCancelSpeechUtterance:(AVSpeechUtterance * _Nonnull)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer didContinueSpeechUtterance:(AVSpeechUtterance * _Nonnull)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer * _Nonnull)synthesizer willSpeakRangeOfSpeechString:(NSRange)characterRange utterance:(AVSpeechUtterance * _Nonnull)utterance;
@end

@class ProximiioAmenity;
@class ProximiioGeoJSON;

SWIFT_CLASS("_TtC15ProximiioMapbox11PIODatabase")
@interface PIODatabase : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
+ (PIODatabase * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
- (NSArray<ProximiioAmenity *> * _Nonnull)amenities SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, copy) NSArray<ProximiioGeoJSON *> * _Nonnull _featuresDb;
- (NSArray<ProximiioGeoJSON *> * _Nonnull)features SWIFT_WARN_UNUSED_RESULT;
- (NSArray<ProximiioGeoJSON *> * _Nonnull)pois SWIFT_WARN_UNUSED_RESULT;
- (NSArray<ProximiioGeoJSON *> * _Nonnull)poisAndLevelChanger SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox19PIODecisionCallback_")
@protocol PIODecisionCallback
- (void)decisionEnteredWithSegment:(ProximiioGeoJSON * _Nonnull)segment;
- (void)decisionExitedWithSegment:(ProximiioGeoJSON * _Nonnull)segment;
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox9PIOFilter_")
@protocol PIOFilter
- (NSString * _Nonnull)filterTag SWIFT_WARN_UNUSED_RESULT;
- (NSArray<NSString *> * _Nonnull)inputNames SWIFT_WARN_UNUSED_RESULT;
- (BOOL)filterItemWithFeature:(ProximiioGeoJSON * _Nonnull)feature input:(NSArray<NSString *> * _Nonnull)input SWIFT_WARN_UNUSED_RESULT;
@end

typedef SWIFT_ENUM(NSInteger, PIOGuidanceDirection, closed) {
  PIOGuidanceDirectionNone = 0,
  PIOGuidanceDirectionStart = 1,
  PIOGuidanceDirectionTurnAround = 2,
  PIOGuidanceDirectionFinish = 3,
  PIOGuidanceDirectionStraight = 4,
/// turn types
  PIOGuidanceDirectionLeftSlight = 5,
/// turn types
  PIOGuidanceDirectionLeftNormal = 6,
/// turn types
  PIOGuidanceDirectionLeftHard = 7,
  PIOGuidanceDirectionRightSlight = 8,
  PIOGuidanceDirectionRightNormal = 9,
  PIOGuidanceDirectionRightHard = 10,
/// level change
  PIOGuidanceDirectionUpElevator = 11,
/// level change
  PIOGuidanceDirectionUpEscalator = 12,
/// level change
  PIOGuidanceDirectionUpStairs = 13,
  PIOGuidanceDirectionDownElevator = 14,
  PIOGuidanceDirectionDownEscalator = 15,
  PIOGuidanceDirectionDownStairs = 16,
};


SWIFT_PROTOCOL("_TtP15ProximiioMapbox17PIOHazardCallback_")
@protocol PIOHazardCallback
- (void)enteredHazardRangeWithHazard:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)exitedHazardRangeWithHazard:(ProximiioGeoJSON * _Nonnull)hazard;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox10PIOHeading")
@interface PIOHeading : NSObject
@property (nonatomic, copy) NSString * _Nonnull text;
@property (nonatomic) double rotation;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox28PIOHeadingCorrectionCallback_")
@protocol PIOHeadingCorrectionCallback
- (void)onHeadingCorrectionWithDegress:(double)degress;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox11PIOLandmark")
@interface PIOLandmark : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox19PIOLandmarkCallback_")
@protocol PIOLandmarkCallback
- (void)onLandmarkEnteredRangeWithLandmarkList:(NSArray<PIOLandmark *> * _Nonnull)landmarkList;
- (void)onLandmarkExitedRangeWithLandmarkList:(NSArray<ProximiioGeoJSON *> * _Nonnull)landmarkList;
@end

typedef SWIFT_ENUM(NSInteger, PIOLandmarkSide, closed) {
  PIOLandmarkSideLeft = 0,
  PIOLandmarkSideRight = 1,
};

@protocol PIOSegmentCallback;

SWIFT_PROTOCOL("_TtP15ProximiioMapbox21PIONavigationDelegate_")
@protocol PIONavigationDelegate
- (void)setStepImmediateThresholdInMeters:(double)threshold;
- (void)setStepPreparationThresholdInMeters:(double)threshold;
- (void)setRouteFinishThresholdInMeters:(double)threshold;
- (void)setReRoutingInMeters:(double)threshold;
- (void)setReRoutingWithAutomatic:(BOOL)automatic;
- (void)setUnitConversionWithUnitName:(NSString * _Nonnull)name conversionCoefficiente:(double)coefficient;
- (void)hazardCallbackWithCallback:(id <PIOHazardCallback> _Nullable)callback;
- (void)segmentCallbackWithCallback:(id <PIOSegmentCallback> _Nullable)callback;
- (void)decisionCallbackWithCallback:(id <PIODecisionCallback> _Nullable)callback;
- (void)headingCorrectionCallbackWithCallback:(id <PIOHeadingCorrectionCallback> _Nullable)callback;
- (void)landmarksCallbackWithCallback:(id <PIOLandmarkCallback> _Nullable)callback;
- (void)ttsEnableWithEnable:(BOOL)enable;
- (void)ttsDisable;
- (void)ttsHazardAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsSegmentAlertWithEnterEnabled:(BOOL)enterEnabled exitEnabled:(BOOL)exitEnabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsDecisionAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsLevelChangerMetadataKeysWithMetadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsHeadingCorrectionWithEnabled:(BOOL)enabled;
- (void)ttsHeadingCorrectionThresholdWithMeters:(double)meters degrees:(double)degrees;
- (void)ttsLandmarkAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsMetadataKeysWithIndexes:(NSArray<NSNumber *> * _Nonnull)indexes;
- (void)ttsRepeatLastInstruction;
- (void)ttsReassuranceInstructionWithEnabled:(BOOL)enabled;
- (void)ttsReassuranceInstructionWithDistance:(double)distance;
- (void)ttsSoonUpdateThresholdWithThresholdMeters:(double)thresholdMeters;
- (void)routeCancelWithSilent:(BOOL)silent;
- (BOOL)routePreview SWIFT_WARN_UNUSED_RESULT;
- (BOOL)routeStart SWIFT_WARN_UNUSED_RESULT;
- (void)processUserLocation:(CLLocationCoordinate2D)position force:(BOOL)force;
- (void)updateUserLevelWithLevel:(NSInteger)level;
@end

@protocol PIONavigationProtocol;
@protocol PIONavigationRouting;
@class MGLMapView;
@class PIORoute;
@class ProximiioPointOnLine;
@protocol PIORouteDelegate;
@class PIORouteOptions;

SWIFT_CLASS("_TtC15ProximiioMapbox13PIONavigation")
@interface PIONavigation : NSObject <PIONavigationDelegate>
@property (nonatomic, weak) id <PIONavigationProtocol> _Nullable delegate;
@property (nonatomic, weak) id <PIONavigationRouting> _Nullable reRoutingDelegate;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (void)setStepImmediateThresholdInMeters:(double)threshold;
- (void)setStepPreparationThresholdInMeters:(double)threshold;
- (void)setRouteFinishThresholdInMeters:(double)threshold;
- (void)setReRoutingInMeters:(double)threshold;
- (void)setReRoutingWithAutomatic:(BOOL)automatic;
- (void)setMapboxMapWithMapboxMap:(MGLMapView * _Nonnull)mapboxMap;
- (void)setUnitConversionWithUnitName:(NSString * _Nonnull)name conversionCoefficiente:(double)coefficient;
- (void)hazardCallbackWithCallback:(id <PIOHazardCallback> _Nullable)callback;
- (void)segmentCallbackWithCallback:(id <PIOSegmentCallback> _Nullable)callback;
- (void)decisionCallbackWithCallback:(id <PIODecisionCallback> _Nullable)callback;
- (void)headingCorrectionCallbackWithCallback:(id <PIOHeadingCorrectionCallback> _Nullable)callback;
- (void)ttsLandmarkAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)landmarksCallbackWithCallback:(id <PIOLandmarkCallback> _Nullable)callback;
- (void)ttsEnableWithEnable:(BOOL)enable;
- (void)ttsDisable;
- (void)ttsHazardAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsSegmentAlertWithEnterEnabled:(BOOL)enterEnabled exitEnabled:(BOOL)exitEnabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsDecisionAlertWithEnabled:(BOOL)enabled metadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsLevelChangerMetadataKeysWithMetadataKeys:(NSArray<NSNumber *> * _Nonnull)metadataKeys;
- (void)ttsHeadingCorrectionWithEnabled:(BOOL)enabled;
- (void)ttsHeadingCorrectionThresholdWithMeters:(double)meters degrees:(double)degrees;
- (void)ttsMetadataKeysWithIndexes:(NSArray<NSNumber *> * _Nonnull)indexes;
- (void)ttsRepeatLastInstruction;
- (void)ttsReassuranceInstructionWithEnabled:(BOOL)enabled;
- (void)ttsReassuranceInstructionWithDistance:(double)distance;
- (void)ttsSoonUpdateThresholdWithThresholdMeters:(double)thresholdMeters;
@property (nonatomic, strong) PIORoute * _Nullable route;
@property (nonatomic) NSInteger routeLastNodeIndex;
@property (nonatomic, copy) NSArray<ProximiioGeoJSON *> * _Nonnull remainingRoute;
@property (nonatomic, strong) ProximiioPointOnLine * _Nullable closestPointToRoute;
@property (nonatomic, weak) id <PIORouteDelegate> _Nullable routeDelegate;
- (void)routeFindFrom:(CLLocationCoordinate2D)from fromLevel:(NSInteger)fromLevel to:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options previewRoute:(BOOL)previewRoute startRoute:(BOOL)startRoute featureList:(NSArray<ProximiioGeoJSON *> * _Nonnull)featureList isReRouting:(BOOL)isReRouting;
- (void)routeCancelWithSilent:(BOOL)silent;
- (BOOL)routePreview SWIFT_WARN_UNUSED_RESULT;
- (BOOL)routeStart SWIFT_WARN_UNUSED_RESULT;
- (void)processUserLocation:(CLLocationCoordinate2D)position force:(BOOL)force;
- (void)updateUserLevelWithLevel:(NSInteger)level;
@end


@class PIORouteNode;

SWIFT_PROTOCOL("_TtP15ProximiioMapbox21PIONavigationProtocol_")
@protocol PIONavigationProtocol
- (void)onProcessNode:(PIORouteNode * _Nullable)node;
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox20PIONavigationRouting_")
@protocol PIONavigationRouting
- (void)onRequestReRoute;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox15PIOReachability")
@interface PIOReachability : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox8PIORoute")
@interface PIORoute : NSObject
@property (nonatomic, strong) ProximiioGeoJSON * _Nonnull destination;
@property (nonatomic) BOOL isPreview;
@property (nonatomic, readonly, copy) NSArray<PIORouteNode *> * _Nonnull nodeList;
- (NSArray<ProximiioGeoJSON *> * _Nonnull)getLineStringFeatureList SWIFT_WARN_UNUSED_RESULT;
- (NSArray<ProximiioGeoJSON *> * _Nonnull)getLineStringListFromStart:(NSInteger)start point:(CLLocationCoordinate2D)point SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface PIORoute (SWIFT_EXTENSION(ProximiioMapbox))
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id> * _Nonnull summary;
@end

enum PIORouteUpdateType : NSInteger;
@class PIORouteUpdateData;

SWIFT_PROTOCOL("_TtP15ProximiioMapbox16PIORouteDelegate_")
@protocol PIORouteDelegate
- (void)onRouteWithRoute:(PIORoute * _Nullable)route;
- (void)routeEventWithEventType:(enum PIORouteUpdateType)type text:(NSString * _Nonnull)text additionalText:(NSString * _Nullable)additionalText data:(PIORouteUpdateData * _Nullable)data;
- (void)onHazardEntered:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentEntered:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onDecisionEntered:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkEntered:(NSArray<PIOLandmark *> * _Nonnull)landmark;
- (void)onHazardExit:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentExit:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onDecisionExit:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkExit:(NSArray<ProximiioGeoJSON *> * _Nonnull)landmark;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox15PIORouteHeading")
@interface PIORouteHeading : CLHeading
@property (nonatomic) CLLocationDirection magneticHeading;
@property (nonatomic) CLLocationDirection trueHeading;
@property (nonatomic) CLLocationDirection headingAccuracy;
@property (nonatomic, copy) NSDate * _Nonnull timestamp;
@property (nonatomic) CLHeadingComponentValue x;
@property (nonatomic) CLHeadingComponentValue y;
@property (nonatomic) CLHeadingComponentValue z;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
- (void)encodeWithCoder:(NSCoder * _Nonnull)coder;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox12PIORouteNode")
@interface PIORouteNode : NSObject
@property (nonatomic) double bearingFromLastNode;
@property (nonatomic, strong) CLLocation * _Nonnull coordinates;
@property (nonatomic) enum PIOGuidanceDirection direction;
@property (nonatomic) double distanceFromLastNode;
@property (nonatomic) NSInteger level;
@property (nonatomic, copy) NSString * _Nullable levelChangerId;
@property (nonatomic, strong) ProximiioGeoJSON * _Nullable lineStringFeatureTo;
@property (nonatomic, copy) NSArray<NSValue *> * _Nonnull lineStringCoordinates;
@property (nonatomic, readonly, copy) NSString * _Nonnull text;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15ProximiioMapbox15PIORouteOptions")
@interface PIORouteOptions : NSObject
@property (nonatomic) BOOL avoidBarriers;
@property (nonatomic) BOOL avoidElevators;
@property (nonatomic) BOOL avoidEscalators;
@property (nonatomic) BOOL avoidNarrowPaths;
@property (nonatomic) BOOL avoidRamps;
@property (nonatomic) BOOL avoidRevolvingDoors;
@property (nonatomic) BOOL avoidStairs;
@property (nonatomic) BOOL avoidTicketGates;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNumber;

SWIFT_CLASS("_TtC15ProximiioMapbox18PIORouteUpdateData")
@interface PIORouteUpdateData : NSObject
@property (nonatomic) NSInteger nodeIndex;
@property (nonatomic) double stepBearing;
@property (nonatomic) enum PIOGuidanceDirection stepDirection;
@property (nonatomic) double stepDistance;
@property (nonatomic, strong) NSNumber * _Nullable nextStepBearing;
@property (nonatomic, strong) NSNumber * _Nullable nextStepDistance;
@property (nonatomic) enum PIOGuidanceDirection nextStepDirection;
@property (nonatomic) CLLocationCoordinate2D position;
@property (nonatomic) double pathLengthRemaining;
@property (nonatomic, readonly, strong) PIOHeading * _Nonnull stepHeading;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, PIORouteUpdateType, closed) {
  PIORouteUpdateTypeCalculating = 0,
  PIORouteUpdateTypeRecalculating = 1,
  PIORouteUpdateTypeRouteNotfound = 2,
  PIORouteUpdateTypeCanceled = 3,
  PIORouteUpdateTypeFinished = 4,
  PIORouteUpdateTypeNew = 5,
  PIORouteUpdateTypeUpdate = 6,
  PIORouteUpdateTypeSoon = 7,
  PIORouteUpdateTypeImmediate = 8,
};


SWIFT_PROTOCOL("_TtP15ProximiioMapbox18PIOSegmentCallback_")
@protocol PIOSegmentCallback
- (void)onSegmentEnteredWithSegment:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onSegmentLeftWithSegment:(ProximiioGeoJSON * _Nonnull)segment;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox12PIOTelemetry")
@interface PIOTelemetry : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) PIOTelemetry * _Nonnull shared;)
+ (PIOTelemetry * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic) BOOL isActive;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox20PIOTelemetryProtocol_")
@protocol PIOTelemetryProtocol
@property (nonatomic, copy) NSDate * _Nonnull date;
@property (nonatomic, copy) NSString * _Nonnull identifier;
- (NSDictionary<NSString *, id> * _Nonnull)toDictionary SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC15ProximiioMapbox12PIOWayfinder")
@interface PIOWayfinder : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) PIOWayfinder * _Nonnull shared;)
+ (PIOWayfinder * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (PIORoute * _Nullable)findRouteFrom:(CLLocationCoordinate2D)from fromLevel:(NSInteger)fromLevel to:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options featureList:(NSArray<ProximiioGeoJSON *> * _Nonnull)featureList telemetry:(BOOL)telemetry isReRouting:(BOOL)isReRouting SWIFT_WARN_UNUSED_RESULT;
- (NSArray<ProximiioGeoJSON *> * _Nullable)findPathWithStartLatitude:(double)startLatitude startLongitude:(double)startLongitude startLevel:(NSInteger)startLevel endLatitude:(double)endLatitude endLongitude:(double)endLongitude endLevel:(NSInteger)endLevel routeOptions:(PIORouteOptions * _Nonnull)routeOptions featureList:(NSArray<ProximiioGeoJSON *> * _Nonnull)featureList SWIFT_WARN_UNUSED_RESULT;
@end







@protocol ProximiioMapboxInteraction;
@protocol ProximiioMapboxNavigation;
@class ProximiioLocation;
@class ProximiioFloor;
@class ProximiioMapboxConfiguration;
enum ProximiioMapboxAuthorizationResult : NSInteger;

SWIFT_CLASS("_TtC15ProximiioMapbox15ProximiioMapbox")
@interface ProximiioMapbox : NSObject <NSURLSessionDelegate>
@property (nonatomic) BOOL shakyHandsMode;
@property (nonatomic, weak) id <ProximiioMapboxInteraction> _Nullable mapInteraction;
@property (nonatomic, weak) id <ProximiioMapboxNavigation> _Nullable mapNavigation;
@property (nonatomic, weak) MGLMapView * _Nullable mapView;
@property (nonatomic, readonly, copy) NSURL * _Nullable styleURL;
@property (nonatomic, strong) ProximiioLocation * _Nullable userLocation;
@property (nonatomic, strong) ProximiioFloor * _Nullable userFloor;
@property (nonatomic) NSInteger mapFloor;
@property (nonatomic, strong) PIODatabase * _Nonnull database;
/// manage the follow heading replacing the one provided by mapbox
@property (nonatomic) BOOL followingUser;
- (void)routeWithDestination:(ProximiioGeoJSON * _Nonnull)destination preview:(BOOL)preview options:(PIORouteOptions * _Nullable)options;
- (void)setConfigurationWithNewConfiguration:(ProximiioMapboxConfiguration * _Nonnull)newConfiguration;
- (void)initialize:(void (^ _Nonnull)(enum ProximiioMapboxAuthorizationResult))completion;
- (nonnull instancetype)initWithMapView:(MGLMapView * _Nullable)mapView configuration:(ProximiioMapboxConfiguration * _Nonnull)configuration OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end






@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox)) <PIONavigationRouting>
- (void)onRequestReRoute;
@end


@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox))
- (void)centerAtUserWithZoom:(double)zoom animated:(BOOL)animated completed:(void (^ _Nullable)(BOOL))completed;
- (void)centerAtFeature:(ProximiioGeoJSON * _Nonnull)feature zoom:(double)zoom animated:(BOOL)animated completed:(void (^ _Nullable)(ProximiioGeoJSON * _Nonnull))completed;
@end






@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox)) <MGLMapViewDelegate>
@end




@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox))
- (void)floorUp;
- (void)floorDown;
- (void)floorAt:(NSInteger)floor;
@end


@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox))
- (void)setLevelWithLevel:(NSInteger)level;
@end


@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox))
- (void)routeFindFrom:(ProximiioGeoJSON * _Nonnull)from to:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options previewRoute:(BOOL)previewRoute startRoute:(BOOL)startRoute;
- (void)routeFindFrom:(CLLocation * _Nonnull)from level:(NSInteger)level to:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options previewRoute:(BOOL)previewRoute startRoute:(BOOL)startRoute;
- (void)routeFindTo:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options;
- (void)routeFindAndStartTo:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options;
- (void)routeFindAndPreviewTo:(ProximiioGeoJSON * _Nonnull)to options:(PIORouteOptions * _Nonnull)options;
- (void)routeStart:(PIORoute * _Nullable)route;
- (void)routeCancelWithSilent:(BOOL)silent;
- (void)routePreview:(PIORoute * _Nullable)route;
- (void)repeatLastInstruction;
@end


@interface ProximiioMapbox (SWIFT_EXTENSION(ProximiioMapbox)) <PIORouteDelegate>
- (void)onHazardExit:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentExit:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onDecisionExit:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkExit:(NSArray<ProximiioGeoJSON *> * _Nonnull)landmark;
- (void)onDecisionEntered:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkEntered:(NSArray<PIOLandmark *> * _Nonnull)landmarks;
- (void)onHazardEntered:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentEntered:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onRouteWithRoute:(PIORoute * _Nullable)route;
- (void)routeEventWithEventType:(enum PIORouteUpdateType)type text:(NSString * _Nonnull)text additionalText:(NSString * _Nullable)additionalText data:(PIORouteUpdateData * _Nullable)data;
@end

typedef SWIFT_ENUM(NSInteger, ProximiioMapboxAuthorizationResult, closed) {
  ProximiioMapboxAuthorizationResultSuccess = 0,
  ProximiioMapboxAuthorizationResultInvalid = 1,
  ProximiioMapboxAuthorizationResultFailure = 2,
};

@class UIImage;

SWIFT_CLASS("_TtC15ProximiioMapbox28ProximiioMapboxConfiguration")
@interface ProximiioMapboxConfiguration : NSObject
@property (nonatomic) BOOL showRasterFloorplans;
@property (nonatomic) BOOL showGeoJSONFloorplans;
@property (nonatomic) BOOL showPOIs;
@property (nonatomic) BOOL showUserLocation;
@property (nonatomic, strong) UIImage * _Nonnull routeStartImage;
@property (nonatomic, strong) UIImage * _Nonnull routeFinishImage;
- (nonnull instancetype)initWithToken:(NSString * _Nonnull)token OBJC_DESIGNATED_INITIALIZER;
- (BOOL)isEqual:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox26ProximiioMapboxInteraction_")
@protocol ProximiioMapboxInteraction
- (void)changeWithFloor:(NSInteger)floor;
- (void)onTapWithFeature:(ProximiioGeoJSON * _Nonnull)feature;
- (void)onRequestReRoute;
- (void)onFollowingUserUpdate:(BOOL)isFollowing;
@end


SWIFT_PROTOCOL("_TtP15ProximiioMapbox25ProximiioMapboxNavigation_")
@protocol ProximiioMapboxNavigation
- (void)onRouteWithRoute:(PIORoute * _Nullable)route;
- (void)routeEventWithEventType:(enum PIORouteUpdateType)type text:(NSString * _Nonnull)text additionalText:(NSString * _Nullable)additionalText data:(PIORouteUpdateData * _Nullable)data;
- (void)onHazardEntered:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentEntered:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onDecisionEntered:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkEntered:(NSArray<PIOLandmark *> * _Nonnull)landmarks;
- (void)onHazardExit:(ProximiioGeoJSON * _Nonnull)hazard;
- (void)onSegmentExit:(ProximiioGeoJSON * _Nonnull)segment;
- (void)onDecisionExit:(ProximiioGeoJSON * _Nonnull)decision;
- (void)onLandmarkExit:(NSArray<ProximiioGeoJSON *> * _Nonnull)landmarks;
- (void)onPositionUpdate:(CLLocationCoordinate2D)position;
- (void)onHeadingUpdate:(double)heading;
@end

typedef SWIFT_ENUM(NSInteger, ProximiioMapboxNetworkResult, closed) {
  ProximiioMapboxNetworkResultSuccess = 0,
  ProximiioMapboxNetworkResultFailure = 1,
};





#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
