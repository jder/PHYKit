//
//  CDStructures.h
//  PHYKit
//
//  Created by Nathan Trapp on 7/27/13.
//  Copyright (c) 2013 Nathan Trapp and Zev Eisenberg. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

@class NSMutableDictionary;

#pragma mark Named Structures

//struct CGPoint {
//    float x;
//    float y;
//};
//
//struct CGRect {
//    struct CGPoint _field1;
//    struct CGSize _field2;
//};
//
//struct CGSize {
//    float width;
//    float height;
//};

struct PHYContactListener {
    void **_vptr$b2ContactListener;
    NSMutableDictionary *_contacts;
    id _contactDelegate;
};

struct b2Block;

struct b2BlockAllocator {
    struct b2Chunk *_field1;
    int _field2;
    int _field3;
    struct b2Block *_field4[14];
};

struct b2Body {
    _Bool _field1;
    unsigned int _field2;
    unsigned int _field3;
    unsigned int _field4;
    int _field5;
    unsigned short _field6;
    int _field7;
    struct b2Transform _field8;
    struct b2Sweep _field9;
    struct b2Vec2 _field10;
    float _field11;
    struct b2Vec2 _field12;
    float _field13;
    struct b2World *_field14;
    struct b2Body *_field15;
    struct b2Body *_field16;
    struct b2Fixture *_field17;
    int _field18;
    struct b2JointEdge *_field19;
    struct b2ContactEdge *_field20;
    float _field21;
    float _field22;
    float _field23;
    float _field24;
    float _field25;
    float _field26;
    float _field27;
    float _field28;
    void *_field29;
};

struct b2BodyDef {
    _Bool _sk_affectedByGravity;
    unsigned int _sk_categoryBitMask;
    unsigned int _sk_collisionBitMask;
    unsigned int _sk_intersectionCallbackBitMask;
    int type;
    struct b2Vec2 position;
    float angle;
    struct b2Vec2 linearVelocity;
    float angularVelocity;
    float linearDamping;
    float angularDamping;
    _Bool allowSleep;
    _Bool awake;
    _Bool fixedRotation;
    _Bool bullet;
    _Bool active;
    void *userData;
    float gravityScale;
};

struct b2BroadPhase {
    struct b2DynamicTree _field1;
    int _field2;
    int *_field3;
    int _field4;
    int _field5;
    struct b2Pair *_field6;
    int _field7;
    int _field8;
    int _field9;
};

struct b2Chunk;

struct b2Contact;

struct b2ContactEdge;

struct b2ContactFilter;

struct b2ContactListener;

struct b2ContactManager {
    struct b2BroadPhase _field1;
    struct b2Contact *_field2;
    int _field3;
    struct b2ContactFilter *_field4;
    struct b2ContactListener *_field5;
    struct b2BlockAllocator *_field6;
};

struct b2DestructionListener;

struct b2DistanceJoint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
    float _field12;
    float _field13;
    float _field14;
    struct b2Vec2 _field15;
    struct b2Vec2 _field16;
    float _field17;
    float _field18;
    float _field19;
    int _field20;
    int _field21;
    struct b2Vec2 _field22;
    struct b2Vec2 _field23;
    struct b2Vec2 _field24;
    struct b2Vec2 _field25;
    struct b2Vec2 _field26;
    float _field27;
    float _field28;
    float _field29;
    float _field30;
    float _field31;
};

struct b2DistanceJointDef {
    int type;
    void *userData;
    struct b2Body *bodyA;
    struct b2Body *bodyB;
    _Bool collideConnected;
    struct b2Vec2 localAnchorA;
    struct b2Vec2 localAnchorB;
    float length;
    float frequencyHz;
    float dampingRatio;
};

struct b2Draw;

struct b2DynamicTree {
    int _field1;
    struct b2TreeNode *_field2;
    int _field3;
    int _field4;
    int _field5;
    unsigned int _field6;
    int _field7;
};

struct b2Filter {
    unsigned int categoryBits;
    unsigned int maskBits;
    unsigned int groupIndex;
};

struct b2Fixture {
    float _field1;
    struct b2Fixture *_field2;
    struct b2Body *_field3;
    struct b2Shape *_field4;
    float _field5;
    float _field6;
    struct b2FixtureProxy *_field7;
    int _field8;
    struct b2Filter _field9;
    _Bool _field10;
    void *_field11;
};

struct b2FixtureDef {
    struct b2Shape *shape;
    void *userData;
    float friction;
    float restitution;
    float density;
    _Bool isSensor;
    struct b2Filter filter;
};

struct b2FixtureProxy;

struct b2Joint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
};

struct b2JointDef {
    int _field1;
    void *_field2;
    struct b2Body *_field3;
    struct b2Body *_field4;
    _Bool _field5;
};

struct b2JointEdge {
    struct b2Body *_field1;
    struct b2Joint *_field2;
    struct b2JointEdge *_field3;
    struct b2JointEdge *_field4;
};

struct b2Mat33 {
    struct b2Vec3 _field1;
    struct b2Vec3 _field2;
    struct b2Vec3 _field3;
};

struct b2Pair;

struct b2PrismaticJoint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
    struct b2Vec2 _field12;
    struct b2Vec2 _field13;
    struct b2Vec2 _field14;
    struct b2Vec2 _field15;
    float _field16;
    struct b2Vec3 _field17;
    float _field18;
    float _field19;
    float _field20;
    float _field21;
    float _field22;
    _Bool _field23;
    _Bool _field24;
    int _field25;
    int _field26;
    int _field27;
    struct b2Vec2 _field28;
    struct b2Vec2 _field29;
    float _field30;
    float _field31;
    float _field32;
    float _field33;
    struct b2Vec2 _field34;
    struct b2Vec2 _field35;
    float _field36;
    float _field37;
    float _field38;
    float _field39;
    struct b2Mat33 _field40;
    float _field41;
};

struct b2PrismaticJointDef {
    int type;
    void *userData;
    struct b2Body *bodyA;
    struct b2Body *bodyB;
    _Bool collideConnected;
    struct b2Vec2 localAnchorA;
    struct b2Vec2 localAnchorB;
    struct b2Vec2 localAxisA;
    float referenceAngle;
    _Bool enableLimit;
    float lowerTranslation;
    float upperTranslation;
    _Bool enableMotor;
    float maxMotorForce;
    float motorSpeed;
};

struct b2RevoluteJoint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
    struct b2Vec2 _field12;
    struct b2Vec2 _field13;
    struct b2Vec3 _field14;
    float _field15;
    _Bool _field16;
    float _field17;
    float _field18;
    _Bool _field19;
    float _field20;
    float _field21;
    float _field22;
    int _field23;
    int _field24;
    struct b2Vec2 _field25;
    struct b2Vec2 _field26;
    struct b2Vec2 _field27;
    struct b2Vec2 _field28;
    float _field29;
    float _field30;
    float _field31;
    float _field32;
    struct b2Mat33 _field33;
    float _field34;
    int _field35;
};

struct b2RevoluteJointDef {
    int type;
    void *userData;
    struct b2Body *bodyA;
    struct b2Body *bodyB;
    _Bool collideConnected;
    struct b2Vec2 localAnchorA;
    struct b2Vec2 localAnchorB;
    float referenceAngle;
    _Bool enableLimit;
    float lowerAngle;
    float upperAngle;
    _Bool enableMotor;
    float motorSpeed;
    float maxMotorTorque;
};

struct b2RopeJoint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
    struct b2Vec2 _field12;
    struct b2Vec2 _field13;
    float _field14;
    float _field15;
    float _field16;
    int _field17;
    int _field18;
    struct b2Vec2 _field19;
    struct b2Vec2 _field20;
    struct b2Vec2 _field21;
    struct b2Vec2 _field22;
    struct b2Vec2 _field23;
    float _field24;
    float _field25;
    float _field26;
    float _field27;
    float _field28;
    int _field29;
};

struct b2RopeJointDef {
    int type;
    void *userData;
    struct b2Body *bodyA;
    struct b2Body *bodyB;
    _Bool collideConnected;
    struct b2Vec2 localAnchorA;
    struct b2Vec2 localAnchorB;
    float maxLength;
};

struct b2Rot {
    float _field1;
    float _field2;
};

struct b2Shape;

struct b2StackAllocator {
    char _field1[102400];
    int _field2;
    int _field3;
    int _field4;
    struct b2StackEntry _field5[32];
    int _field6;
};

struct b2StackEntry {
    char *_field1;
    int _field2;
    _Bool _field3;
};

struct b2Sweep {
    struct b2Vec2 _field1;
    struct b2Vec2 _field2;
    struct b2Vec2 _field3;
    float _field4;
    float _field5;
    float _field6;
};

struct b2Transform {
    struct b2Vec2 _field1;
    struct b2Rot _field2;
};

struct b2TreeNode;

struct b2Vec2 {
    float x;
    float y;
};

struct b2Vec3 {
    float _field1;
    float _field2;
    float _field3;
};

struct b2WeldJoint {
    void **_field1;
    int _field2;
    struct b2Joint *_field3;
    struct b2Joint *_field4;
    struct b2JointEdge _field5;
    struct b2JointEdge _field6;
    struct b2Body *_field7;
    struct b2Body *_field8;
    _Bool _field9;
    _Bool _field10;
    void *_field11;
    struct b2Vec2 _field12;
    struct b2Vec2 _field13;
    float _field14;
    struct b2Vec3 _field15;
    int _field16;
    int _field17;
    struct b2Vec2 _field18;
    struct b2Vec2 _field19;
    struct b2Vec2 _field20;
    struct b2Vec2 _field21;
    float _field22;
    float _field23;
    float _field24;
    float _field25;
    struct b2Mat33 _field26;
};

struct b2WeldJointDef {
    int type;
    void *userData;
    struct b2Body *bodyA;
    struct b2Body *bodyB;
    _Bool collideConnected;
    struct b2Vec2 localAnchorA;
    struct b2Vec2 localAnchorB;
    float referenceAngle;
};

struct b2World {
    struct b2BlockAllocator _field1;
    struct b2StackAllocator _field2;
    int _field3;
    struct b2ContactManager _field4;
    struct b2Body *_field5;
    struct b2Joint *_field6;
    int _field7;
    int _field8;
    struct b2Vec2 _field9;
    _Bool _field10;
    struct b2DestructionListener *_field11;
    struct b2Draw *_field12;
    float _field13;
    _Bool _field14;
    _Bool _field15;
    _Bool _field16;
    _Bool _field17;
};

