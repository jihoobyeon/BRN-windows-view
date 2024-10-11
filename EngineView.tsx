import { ElementRef, forwardRef, JSX, Ref, useImperativeHandle, useRef } from 'react';
import type { HostComponent, ViewProps } from 'react-native';
import type { DirectEventHandler, Double, Int32 } from 'react-native/Libraries/Types/CodegenTypes';
import EngineViewNativeComponent from './EngineViewNativeComponent.ts';

type SnapshotEvent = { event: Int32 };

export interface NativeEngineViewProps extends ViewProps {
  isTransparent: boolean;
  antiAliasing: Double;
  androidView: string;
  onSnapshotDataReturned?: DirectEventHandler<SnapshotEvent>;
}

function EngineView(props: NativeEngineViewProps, ref: Ref<typeof EngineViewNativeComponent>): JSX.Element {
//  const engineViewRef = useRef<ElementRef<typeof EngineViewNativeComponent>>(null);
  return <EngineViewNativeComponent {...props} />;
}

const EngineViewWithForwardRef = forwardRef(EngineView);
export default EngineViewWithForwardRef;
