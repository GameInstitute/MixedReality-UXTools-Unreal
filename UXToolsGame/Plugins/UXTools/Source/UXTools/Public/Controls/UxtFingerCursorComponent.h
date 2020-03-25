// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Controls/UxtRingCursorComponent.h"
#include "UxtFingerCursorComponent.generated.h"

class UUxtNearPointerComponent;

/**
 * When added to an actor with a touch pointer, this component displays a ring cursor oriented towards the pointer target and 
 * scaled according to the distance.
 */
UCLASS( ClassGroup = UXTools, meta=(BlueprintSpawnableComponent) )
class UXTOOLS_API UUxtFingerCursorComponent : public UUxtRingCursorComponent
{
	GENERATED_BODY()

public:

	UUxtFingerCursorComponent();

	/** Maximum distance to the pointer target at which the cursor should be displayed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finger Cursor")
	float MaxDistanceToTarget = 20.0f;

	/** Cursor radius at the maximum distance to the target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finger Cursor")
	float MaxRadius = 0.85f;

	/** Cursor radius when in contact with the target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Finger Cursor")
	float MinRadius = 0.15f;

protected:

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	/** Distance at which the cursor starts to align with touchable surfaces. */
	UPROPERTY(EditAnywhere, Category = "Finger Cursor")
	float AlignWithSurfaceDistance = 10.0f;

	/** Touch pointer in use. */
	TWeakObjectPtr<UUxtNearPointerComponent> HandPointerWeak;
};
