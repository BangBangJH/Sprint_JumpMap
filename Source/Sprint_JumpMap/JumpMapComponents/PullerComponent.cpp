#include "PullerComponent.h"
#include "PullableComponent.h"


UPullerComponent::UPullerComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UPullerComponent::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UPullerComponent::OnOverlapEnd);
	SetGenerateOverlapEvents(true);
	SetCollisionObjectType(ECC_GameTraceChannel2);
	SetCollisionResponseToAllChannels(ECR_Ignore);
	SetCollisionResponseToChannel(ECC_EngineTraceChannel3, ECR_Overlap);
}


void UPullerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UPullableComponent* PullableComponent = OtherActor->FindComponentByClass<UPullableComponent>();
	if (PullableComponent)
	{
		PullableComponent->StartPulling(GetOwner()->GetActorLocation(), PullingForce);
	}
}

void UPullerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	UPullableComponent* PullableComponent = OtherActor->FindComponentByClass<UPullableComponent>();
	if (PullableComponent)
	{
		PullableComponent->StopPulling();
	}
}